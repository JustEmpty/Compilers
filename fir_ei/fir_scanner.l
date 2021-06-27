%option c++ prefix="fir_scanner_" outfile="fir_scanner.cpp"
%option stack noyywrap yylineno 8bit
%{ 
// make relevant includes before including the parser's tab file
#include <string>
#include <cstring>
#include <vector>
#include <sstream>
#include <cdk/ast/sequence_node.h>
#include <cdk/ast/expression_node.h>
#include <cdk/ast/lvalue_node.h>
#include "fir_parser.tab.h"

// output stream for building string literals
static std::ostringstream strlit;

// don't change this
#define yyerror LexerError
%}

SPACE     ([ \t\r]|\n)

LETTER  [A-Za-z_]
IDENTIFIER   {LETTER}({LETTER}|[[:digit:]])*

%x X_STRING X_COMMENT X_SPECIALCHAR
%%

 /* = KEYWORDS = */

"int"                  return tTYPE_INT;
"float"                return tTYPE_FLOAT;
"string"               return tTYPE_STRING;
"void"                 return tTYPE_VOID;
"null"                 return tNULL;
"return"               return tRETURN;
"sizeof"			   return tSIZEOF;
[<>]                   return *yytext;

 /* = OPERATORS = */

[\[\]()?]              return *yytext;
[-+*/%~<>@?=]          return *yytext;

">="                   return tGE; 
"<="                   return tLE;

"=="                   return tEQ; 
"!="                   return tNE;

"&&"				   return tAND;
"||"                   return tOR;

 /* = READ/WRITE = */

[\[\](){};:]           return *yytext;
"write"                return tWRITE;
"writeln"              return tWRITELN;


 /* = CYCLES = */

"do"                   return tDO;
"while"                return tWHILE;  

 /* = CONDITIONS = */

"if"                   return tIF; 
"then"                 return tTHEN;
"else"                 return tELSE;

 /* = SKIP = */

"finally"              return tFINALLY;
"leave"                return tLEAVE;
"restart"              return tRESTART;
 
 /* = ID = */

{IDENTIFIER}           yylval.s = new std::string(yytext); return tID;

 /* = COMMENTS = */

"!!".*                 ; /* ignore comments */

"(*"                   yy_push_state(X_COMMENT);
<X_COMMENT>"*)"        yy_pop_state();
<X_COMMENT>.|\n        ; /* ignore content */

 /* = STRINGS = */ 

"\'"                   yy_push_state(X_STRING);
<X_STRING>~            yy_push_state(X_SPECIALCHAR);
<X_STRING>"\'"         {
                         yylval.s = new std::string(strlit.str());
                         strlit.str("");
                         yy_pop_state();
                         return tSTRING;
                        }
<X_STRING>\n            yyerror("newline in string");        
<X_STRING>.             strlit << *yytext;


<X_SPECIALCHAR>n                 strlit << '\n'; yy_pop_state();
<X_SPECIALCHAR>r                 strlit << '\r'; yy_pop_state();
<X_SPECIALCHAR>t                 strlit << '\t'; yy_pop_state();
<X_SPECIALCHAR>~                 strlit << '~'; yy_pop_state();

<X_SPECIALCHAR>[[:xdigit:]]{1,2} {
                                   strlit << (char)(unsigned char)strtoul(yytext, NULL, 16);
                                   yy_pop_state();
                                 }
<X_SPECIALCHAR>.                 strlit << *yytext; yy_pop_state();

 /* = INTEGERS = */

0[0-7]+              yylval.i = strtoul(yytext, NULL, 8); return tINTEGER;
0[0-9]+              yyerror("Invalid base 8 number.");

0|[1-9][0-9]*        yylval.i = strtoul(yytext, NULL, 10); return tINTEGER;

 /* = DOUBLES = */

([0-9]*\.[0-9]+|[0-9]+\.[0-9]*)([eE][-+]?[0-9]+)? { yylval.d = strtod(yytext, NULL); return tFLOAT; }

 /* = OTHERS = */

[[:space:]]                                /* ignore remaining white space inside the program */
.                      yyerror(yytext);    /* all other chars: error! */

%%
