%{
//-- don't change *any* of these: if you do, you'll break the compiler.
#include <algorithm>
#include <memory>
#include <cstring>
#include <cdk/compiler.h>
#include <cdk/types/types.h>
#include "ast/all.h"
#define LINE                         compiler->scanner()->lineno()
#define yylex()                      compiler->scanner()->scan()
#define yyerror(compiler, s)         compiler->scanner()->error(s)
//-- don't change *any* of these --- END!
%}

%parse-param {std::shared_ptr<cdk::compiler> compiler}

%union {
  //--- don't change *any* of these: if you do, you'll break the compiler.
  YYSTYPE() : type(cdk::primitive_type::create(0, cdk::TYPE_VOID)) {}
  ~YYSTYPE() {}
  YYSTYPE(const YYSTYPE &other) { *this = other; }
  YYSTYPE& operator=(const YYSTYPE &other) { type = other.type; return *this; }

  std::shared_ptr<cdk::basic_type> type;        /* expression type */
  //-- don't change *any* of these --- END!

  int                   i;	/* integer value */
  double		d;	/* double value */
  std::string          *s;	/* symbol name or string literal */

  cdk::basic_node      *node;	/* node pointer */
  cdk::sequence_node   *sequence;
  cdk::expression_node *expression; /* expression nodes */
  cdk::lvalue_node     *lval;
  cdk::basic_type      *types;

  fir::block_node      *block;
  fir::body_node       *body;
  fir::prologue_node   *prologue;
}

%token tAND tOR tSIZEOF
%token tTYPE_STRING tTYPE_INT tTYPE_FLOAT tTYPE_VOID
%token tINPUT tWRITE tWRITELN
%token tIF tTHEN tELSE
%token tWHILE tDO tFINALLY
%token tLEAVE tRESTART tRETURN
%token tWITH tAPPLY tIN

%token<i> tINTEGER
%token<d> tFLOAT
%token<s> tID tSTRING
%token<expression> tNULL

%nonassoc tIF
%nonassoc tTHEN
%nonassoc tELSE

%nonassoc tWHILE
%nonassoc tDO
%nonassoc tFINALLY

%nonassoc tWITH
%nonassoc tAPPLY
%nonassoc tIN

%type<node> decl argdec vardec fundec fundef inst while ifs funcvar with
%type<sequence> file seq_decl argdecs opt_vardecs opt_inst seq_inst opt_expr seq_expr funcvars
%type<expression> expr integer float opt_init literal
%type<lval> lval
%type<s> string
%type<type> data_type void_type
%type<block> block
%type<body> body
%type<prologue> prologue

%right '='
%left tOR
%left tAND
%right '~'
%left tNE tEQ
%left '<' tLE tGE '>'
%left '+' '-'
%left '*' '/' '%'
%right tUMINUS

%{
//-- The rules below will be included in yyparse, the main parsing function.
%}
%%

file        : /* empty */  { compiler->ast($$ = new cdk::sequence_node(LINE)); }
            | seq_decl     { compiler->ast($$ = $1); }
            ;

seq_decl    : decl           { $$ = new cdk::sequence_node(LINE, $1);}
            | seq_decl decl  { $$ = new cdk::sequence_node(LINE, $2, $1);}
            ;

decl        : vardec ';'  { $$ = $1; }
            | fundec      { $$ = $1; }
            | fundef      { $$ = $1; }
            ;

vardec      : data_type '?' tID            { $$ = new fir::variable_declaration_node(LINE, $1, '?', *$3, nullptr); delete $3; }
            | data_type '*' tID  opt_init  { $$ = new fir::variable_declaration_node(LINE, $1, '*', *$3, $4); delete $3; }
            | data_type     tID  opt_init  { $$ = new fir::variable_declaration_node(LINE, $1, '\0', *$2, $3); delete $2; }
            ;

opt_vardecs : /* empty */  { $$ = NULL; }
            | funcvars      { $$ = $1; }
            ;

funcvar     : data_type tID           { $$ = new fir::variable_declaration_node(LINE,$1, '\0', *$2, nullptr); delete $2; }
            | data_type tID '=' expr  { $$ = new fir::variable_declaration_node(LINE,$1, '\0', *$2, $4); delete $2;      }
            ;

funcvars    : funcvar ';'               { $$ = new cdk::sequence_node(LINE, $1);     }
            | funcvars funcvar ';'      { $$ = new cdk::sequence_node(LINE, $2, $1); }
            ;

data_type   : tTYPE_STRING       { $$ = cdk::primitive_type::create(4, cdk::TYPE_STRING);  }
	    | tTYPE_INT          { $$ = cdk::primitive_type::create(4, cdk::TYPE_INT);     }
	    | tTYPE_FLOAT        { $$ = cdk::primitive_type::create(8, cdk::TYPE_DOUBLE);  }
  	    | '<' data_type '>'  { $$ = cdk::reference_type::create(4, $2); }
	    ;

void_type   : tTYPE_VOID        { $$ = cdk::primitive_type::create(0, cdk::TYPE_VOID);   }
            ;

opt_init    : /* empty */  { $$ = nullptr; /* must be nullptr, not NIL */ }
            | '=' expr     { $$ = $2; }
            ;

argdecs     : /* empty */         { $$ = new cdk::sequence_node(LINE);  }
            |             argdec  { $$ = new cdk::sequence_node(LINE, $1);     }
            | argdecs ',' argdec  { $$ = new cdk::sequence_node(LINE, $3, $1); }
            ;

argdec      : data_type tID  { $$ = new fir::variable_declaration_node(LINE, $1, '\0', *$2, nullptr); }
            ;

fundec      : data_type     tID '(' argdecs ')'  { $$ = new fir::function_declaration_node(LINE, $1, '\0', *$2, $4); delete $2; }
            | data_type '?' tID '(' argdecs ')'  { $$ = new fir::function_declaration_node(LINE, $1, '?', *$3, $5); delete $3; }
            | data_type '*' tID '(' argdecs ')'  { $$ = new fir::function_declaration_node(LINE, $1, '*', *$3, $5); delete $3; }
            | void_type     tID '(' argdecs ')'  { $$ = new fir::function_declaration_node(LINE, $1, '\0', *$2, $4); delete $2; }
            | void_type '?' tID '(' argdecs ')'  { $$ = new fir::function_declaration_node(LINE, $1, '?', *$3, $5); delete $3; }
            | void_type '*' tID '(' argdecs ')'  { $$ = new fir::function_declaration_node(LINE, $1, '*', *$3, $5); delete $3; }
            ;

fundef      : data_type     tID '(' argdecs ')' '-''>' literal body  { $$ = new fir::function_definition_node(LINE, $1, '\0', *$2, $4, $8, $9); delete $2; }
            | data_type '*' tID '(' argdecs ')' '-''>' literal body  { $$ = new fir::function_definition_node(LINE, $1, '*', *$3, $5, $9, $10); delete $3; }
            | data_type     tID '(' argdecs ')' body                 { $$ = new fir::function_definition_node(LINE, $1, '\0', *$2, $4, nullptr, $6); delete $2; }
            | data_type '*' tID '(' argdecs ')' body                 { $$ = new fir::function_definition_node(LINE, $1, '*', *$3, $5, nullptr, $7); delete $3; }
            | void_type     tID '(' argdecs ')' body 		     { $$ = new fir::function_definition_node(LINE, $1, '\0', *$2, $4, nullptr, $6); delete $2; }
            | void_type '*' tID '(' argdecs ')' body 		     { $$ = new fir::function_definition_node(LINE, $1, '*', *$3, $5, nullptr, $7); delete $3; }
            ;

body        : '@' prologue		       { $$ = new fir::body_node(LINE, $2, nullptr, nullptr); }
            | 		    block	       { $$ = new fir::body_node(LINE, nullptr, $1, nullptr); }
            |                    '>''>' block  { $$ = new fir::body_node(LINE, nullptr, nullptr, $3); }
            | '@' prologue block	       { $$ = new fir::body_node(LINE, $2, $3, nullptr); }
            | '@' prologue       '>''>' block  { $$ = new fir::body_node(LINE, $2, nullptr, $5); }
            |              block '>''>' block  { $$ = new fir::body_node(LINE, nullptr, $1, $4); }
            | '@' prologue block '>''>' block  { $$ = new fir::body_node(LINE, $2, $3, $6); }
            ;

prologue    : '{' opt_vardecs opt_inst '}'  { $$ = new fir::prologue_node(LINE, $2, $3); }
	    ;

block       : '{' opt_vardecs opt_inst '}'  { $$ = new fir::block_node(LINE, $2, $3); }
            ;

seq_inst    : inst           { $$ = new cdk::sequence_node(LINE, $1); }
     	    | seq_inst inst  { $$ = new cdk::sequence_node(LINE, $2, $1); }
	    ;

opt_inst    : /* empty */  { $$ = new cdk::sequence_node(LINE); }
            | seq_inst     { $$ = $1; }
            ;

inst        : ifs                    { $$ = $1; }
            | while                  { $$ = $1; }
            | with                   { $$ = $1; }
     	    | expr ';'               { $$ = new fir::evaluation_node(LINE, $1); }
            | tWRITE   seq_expr ';'  { $$ = new fir::write_node(LINE, $2, false); }
     	    | tWRITELN seq_expr ';'  { $$ = new fir::write_node(LINE, $2, true); }
            | tLEAVE ';'             { $$ = new fir::leave_node(LINE); }
            | tLEAVE tINTEGER ';'    { $$ = new fir::leave_node(LINE, $2); }
            | tRESTART ';'           { $$ = new fir::restart_node(LINE); }
            | tRESTART tINTEGER ';'  { $$ = new fir::restart_node(LINE, $2); }
            | tRETURN     	     { $$ = new fir::return_node(LINE); }
            | block                  { $$ = $1; }
            ;

ifs         : tIF expr tTHEN inst             { $$ = new fir::if_node(LINE, $2, $4); }
            | tIF expr tTHEN inst tELSE inst  { $$ = new fir::if_else_node(LINE, $2, $4, $6); }
            ;

while       : tWHILE expr tDO inst  	          { $$ = new fir::while_node(LINE, $2, $4, nullptr); }
            | tWHILE expr tDO inst tFINALLY inst  { $$ = new fir::while_node(LINE, $2, $4, $6); }
            ;

with        : tWITH expr tAPPLY tID tIN expr '.' '.' expr ';' { $$ = new fir::with_node(LINE, $2, *$4, $6, $9); delete $4; }
            ;

opt_expr    : /* empty */  { $$ = new cdk::sequence_node(LINE); }
            | seq_expr     { $$ = $1; }
            ;

seq_expr    : expr               { $$ = new cdk::sequence_node(LINE, $1); }
            | seq_expr ',' expr  { $$ = new cdk::sequence_node(LINE, $3, $1); }
            ;

expr 	    : literal                 { $$ = $1; }
      	    /* ASSIGNMENTS */
      	    | lval '=' expr           { $$ = new cdk::assignment_node(LINE, $1, $3); }
      	    /* ARITHMETIC EXPRESSIONS */
      	    | expr '+' expr           { $$ = new cdk::add_node(LINE, $1, $3); }
      	    | expr '-' expr           { $$ = new cdk::sub_node(LINE, $1, $3); }
      	    | expr '*' expr           { $$ = new cdk::mul_node(LINE, $1, $3); }
      	    | expr '/' expr           { $$ = new cdk::div_node(LINE, $1, $3); }
      	    | expr '%' expr           { $$ = new cdk::mod_node(LINE, $1, $3); }
      	    /* LOGICAL EXPRESSIONS */
      	    | expr '<' expr           { $$ = new cdk::lt_node(LINE, $1, $3); }
      	    | expr tLE expr           { $$ = new cdk::le_node(LINE, $1, $3); }
      	    | expr tEQ expr           { $$ = new cdk::eq_node(LINE, $1, $3); }
      	    | expr tGE expr           { $$ = new cdk::ge_node(LINE, $1, $3); }
      	    | expr '>' expr           { $$ = new cdk::gt_node(LINE, $1, $3); }
      	    | expr tNE expr           { $$ = new cdk::ne_node(LINE, $1, $3); }
      	    | expr tAND expr          { $$ = new cdk::and_node(LINE, $1, $3); }
      	    | expr tOR expr           { $$ = new cdk::or_node (LINE, $1, $3); }
            /* UNARY EXPRESSION */
      	    | '-' expr %prec tUMINUS  { $$ = new cdk::neg_node(LINE, $2); }
      	    | '+' expr %prec tUMINUS  { $$ = new fir::identity_node(LINE, $2);}
      	    | '~' expr                { $$ = new cdk::not_node(LINE, $2); }
      	    /* OTHER EXPRESSION */
      	    | '@'                     { $$ = new fir::input_node(LINE); }
      	    | tID '(' opt_expr ')'    { $$ = new fir::function_call_node(LINE, *$1, $3); delete $1; }
      	    | tSIZEOF '(' expr ')'    { $$ = new fir::sizeof_node(LINE, $3); }
      	    | '(' expr ')'            { $$ = $2; }
      	    | '[' expr ']'            { $$ = new fir::stack_alloc_node(LINE, $2); }
      	    | lval                    { $$ = new cdk::rvalue_node(LINE, $1); }
      	    | lval '?'                { $$ = new fir::address_of_node(LINE, $1); }
      	    ;

lval        : tID	               		 { $$ = new cdk::variable_node(LINE, $1); }
            | lval '[' expr ']'                  { $$ = new fir::index_node(LINE, new cdk::rvalue_node(LINE, $1), $3); }
            | '(' expr ')' '[' expr']'           { $$ = new fir::index_node(LINE, $2, $5); }
            | tID '(' opt_expr ')' '[' expr ']'  { $$ = new fir::index_node(LINE, new fir::function_call_node(LINE, *$1, $3), $6); }
            ;

literal     : integer  { $$ = $1;}
            | float    { $$ = $1;}
            | string   { $$ = new cdk::string_node(LINE, $1);}
            | tNULL    { $$ = new fir::null_node(LINE);}
            ;

integer     : tINTEGER        { $$ = new cdk::integer_node(LINE, $1); };
float       : tFLOAT          { $$ = new cdk::double_node(LINE, $1); };
string      : tSTRING         { $$ = $1; }
            | string tSTRING  { $$ = $1; $$->append(*$2); delete $2; }
	    ;

%%
