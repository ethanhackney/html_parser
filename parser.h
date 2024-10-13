#ifndef PARSER_H
#define PARSER_H

#include "a_node.h"
#include "bold_node.h"
#include "html_node.h"
#include "lexer.h"
#include "text_node.h"
#include <vector>

class parser {
private:
        std::vector<node*> _roots;
        lexer& _lex;

        node* do_parse(void);
        node* parse_tag(void);
        node* parse_a_tag(void);
public:
        parser(lexer& lex);
        void parse(void);
        node* get_root(size_t i);
        size_t n_roots(void);
        ~parser();
};

#endif
