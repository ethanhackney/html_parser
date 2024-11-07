#ifndef PARSER_H
#define PARSER_H

#include "abbr_node.h"
#include "a_node.h"
#include "body_node.h"
#include "bold_node.h"
#include "div_node.h"
#include "html_node.h"
#include "p_node.h"
#include "table_node.h"
#include "area_node.h"
#include "article_node.h"
#include "aside_node.h"
#include "audio_node.h"
#include "b_node.h"
#include "base_node.h"
#include "bdi_node.h"
#include "bdo_node.h"
#include "blockquote_node.h"
#include "br_node.h"
#include "button_node.h"
#include "canvas_node.h"
#include "caption_node.h"
#include "text_node.h"
#include "lexer.h"
#include <vector>

class parser {
private:
        std::vector<node*> _roots;
        lexer& _lex;

        node* do_parse(void);
        node* parse_tag(void);
public:
        parser(lexer& lex);
        void parse(void);
        node* get_root(size_t i);
        size_t n_roots(void);
        ~parser();
};

#endif
