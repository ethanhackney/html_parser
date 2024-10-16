#include "parser.h"

parser::~parser()
{
        for (auto r : _roots)
                delete r;
}

node* parser::get_root(size_t i)
{
        return _roots.at(i);
}

size_t parser::n_roots(void)
{
        return _roots.size();
}

parser::parser(lexer& lex)
        : _lex {lex}
{
        _lex.next();
}

void parser::parse(void)
{
        while (_lex.type() != TOK_EOF)
                _roots.push_back(do_parse());
}

node* parser::do_parse(void)
{
        if (_lex.type() == TOK_LT) {
                return parse_tag();
        } else {
                auto n = new text_node{_lex.lex().c_str()[0]};
                _lex.skip(TOK_CHAR);
                return n;
        }
}

node* parser::parse_tag(void)
{
        _lex.skip(TOK_LT);
        auto type = _lex.type();

        _lex.skip(type);

        node* n;
        if (type == TOK_A_TAG) {
                n = new a_node{};
        } else if (type == TOK_BOLD) {
                n = new bold_node{};
        } else if (type == TOK_HTML) {
                n = new html_node{};
        } else if (type == TOK_P_TAG) {
                n = new p_node{};
        } else if (type == TOK_BODY_TAG) {
                n = new body_node{};
        } else {
                errno = EINVAL;
                err(EX_USAGE, "invalid tagname: %s", token{type}.name().c_str());
        }

        while (_lex.type() != TOK_GT) {
                auto attr = _lex.lex();
                _lex.skip(_lex.type());
                n->set_attr(attr, "on");
                if (_lex.type() == TOK_EQ) {
                        _lex.skip(TOK_EQ);
                        auto v = _lex.lex();
                        _lex.skip(_lex.type());
                        n->set_attr(attr, v);
                }
        }
        _lex.skip(TOK_GT);

        for (;;) {
                if (_lex.type() == TOK_LT) {
                        if (_lex.peek().type() == TOK_SLASH)
                                break;
                }
                n->add_kid(do_parse());
        }

        _lex.skip(TOK_LT);
        _lex.skip(TOK_SLASH);
        _lex.skip(type);
        _lex.skip(TOK_GT);
        return n;
}
