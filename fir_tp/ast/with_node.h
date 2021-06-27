#ifndef __FIR_AST_WITH_NODE_H__
#define __FIR_AST_WITH_NODE_H__

#include <cdk/ast/expression_node.h>

namespace fir {

    /**
     * Class for describing with.
     */
    class with_node: public cdk::basic_node {
        cdk::expression_node * _vector;
        std::string _function;
        cdk::expression_node * _low;
        cdk::expression_node * _high;


    public:
        inline with_node(int lineno, cdk::expression_node *vector,  const std::string &function, cdk::expression_node *low,
                        cdk::expression_node *high) :
                basic_node(lineno),  _vector(vector), _function(function), _low(low), _high(high)  {
        }

    public:
        inline cdk::expression_node *vector() {
            return _vector;
        }
        const std::string& function() {
            return _function;
        }
        inline cdk::expression_node *low() {
            return _low;
        }
        inline cdk::expression_node *high() {
            return _high;
        }

        void accept(basic_ast_visitor *sp, int level) {
            sp->do_with_node(this, level);
        }

    };

} // fir

#endif
