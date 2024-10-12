#include "lexer.h"
#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>

static void cout_space(int space)
{
        for (auto i = 0; i < space; i++)
                std::cout << " ";
}

class node {
public:
        virtual void dump(int space) = 0;
        virtual ~node() {}
};

class text_node : public node {
private:
        int _c;
public:
        text_node(int c);
        virtual void dump(int space);
        virtual ~text_node() {}
};

text_node::text_node(int c)
        : _c {c}
{
}

void text_node::dump(int space)
{
        cout_space(space);
        std::cout << "text_node{\n";
        cout_space(space + 2);
        std::cout << "'" << (char)_c << "'" << "\n";
        cout_space(space);
        std::cout << "}";
}

class a_node : public node {
private:
        std::unordered_map<std::string,std::string> _attrs {};
        std::vector<node*> _kids {};
public:
        void add_kid(node* kid);
        void set_attr(const std::string& attr, const std::string& value);
        virtual void dump(int space);
        virtual ~a_node() {}
        std::string attr_val(const std::string& attr);
};

std::string a_node::attr_val(const std::string& attr)
{
        return _attrs[attr];
}

void a_node::add_kid(node* kid)
{
        _kids.push_back(kid);
}

void a_node::set_attr(const std::string& attr, const std::string& value)
{
        _attrs[attr] = value;
}

void a_node::dump(int space)
{
        cout_space(space);
        std::cout << "a_node{\n";
        for (auto attr : _attrs) {
                cout_space(space + 2);
                std::cout << attr.first << ": " << attr.second << ",\n";
        }

        cout_space(space + 2);
        std::cout << "kids: [\n";
        for (auto k : _kids) {
                k->dump(space + 4);
                std::cout << ",\n";
        }

        cout_space(space);
        std::cout << "}";
}

class bold_node : public node {
private:
        std::vector<node*> _kids;
public:
        bold_node(void);
        virtual void dump(int space);
        void add_kid(node* n);
        virtual ~bold_node() {}
};

bold_node::bold_node(void)
{
}

void bold_node::dump(int space)
{
        cout_space(space);
        std::cout << "bold_node{\n";

        cout_space(space + 2);
        std::cout << "kids: [\n";
        for (auto k : _kids) {
                k->dump(space + 4);
                std::cout << ",\n";
        }
        cout_space(space + 2);
        std::cout << "]\n";

        cout_space(space);
        std::cout << "}";
}

void bold_node::add_kid(node* n)
{
        _kids.push_back(n);
}

class html_node : public node {
private:
        std::vector<node*> _kids;
public:
        html_node(void) {}
        void add_kid(node* n) {_kids.push_back(n);}
        virtual ~html_node() {}
        virtual void dump(int space);
};

void html_node::dump(int space)
{
        cout_space(space);
        std::cout << "html_node{\n";

        cout_space(space + 2);
        std::cout << "kids: [\n";
        for (auto k : _kids) {
                k->dump(space + 4);
                std::cout << ",\n";
        }
        cout_space(space + 2);
        std::cout << "]\n";

        cout_space(space);
        std::cout << "}";
}

class body_node : public node {
private:
        std::vector<node*> _kids;
public:
        body_node(void) {}
        void add_kid(node* n) {_kids.push_back(n);}
        virtual ~body_node() {}
        virtual void dump(int space);
};

void body_node::dump(int space)
{
        cout_space(space);
        std::cout << "body_node{\n";

        cout_space(space + 2);
        std::cout << "kids: [\n";
        for (auto k : _kids) {
                k->dump(space + 4);
                std::cout << ",\n";
        }
        cout_space(space + 2);
        std::cout << "]\n";

        cout_space(space);
        std::cout << "}";
}

node *parse(lexer& lex);
node *parse_tag(lexer& lex);
node *parse_a_tag(lexer& lex);
node *parse_bold_tag(lexer& lex);
node *parse_html_tag(lexer& lex);
node *parse_body_tag(lexer& lex);
void node_free(node* n);

std::vector<node*> nodes;

int main(void)
{
        lexer lex {"index.html"};

        lex.next();
        auto n = parse(lex);

        auto h = static_cast<html_node*>(n);
        h->dump(0);
        node_free(n);
}

node *parse(lexer& lex)
{
        if (lex.type() == TOK_EOF)
                return nullptr;
        else if (lex.type() == TOK_LT)
                return parse_tag(lex);
        else {
                auto n = new text_node{lex.lex().c_str()[0]};
                nodes.push_back(n);
                lex.skip(TOK_CHAR);
                return n;
        }
}

node *parse_tag(lexer& lex)
{
        lex.skip(TOK_LT);
        auto type = lex.type();

        node *n;
        if (type == TOK_A_TAG) {
                n = parse_a_tag(lex);
        } else if (type == TOK_BOLD) {
                n = parse_bold_tag(lex);
        } else if (type == TOK_HTML) {
                n = parse_html_tag(lex);
        } else if (type == TOK_BODY) {
                n = parse_body_tag(lex);
        } else {
                errno = EINVAL;
                err(EX_USAGE, "invalid tagname: %s",
                                lex.name().c_str());
        }

        lex.skip(TOK_LT);
        lex.skip(TOK_SLASH);
        lex.skip(type);
        lex.skip(TOK_GT);
        return n;
}

node *parse_a_tag(lexer& lex)
{
        lex.skip(TOK_A_TAG);

        auto n = new a_node{};
        while (lex.type() != TOK_GT) {
                auto attr = lex.lex();
                lex.next();
                lex.skip(TOK_EQ);
                auto value = lex.lex();
                lex.next();
                n->set_attr(attr, value);
        }
        lex.skip(TOK_GT);

        for (;;) {
                if (lex.type() == TOK_LT) {
                        if (lex.peek().type() == TOK_SLASH)
                                break;
                }
                n->add_kid(parse(lex));
        }

        nodes.push_back(n);
        return n;
}

node *parse_bold_tag(lexer& lex)
{
        auto n = new bold_node{};
        lex.skip(TOK_BOLD);
        lex.skip(TOK_GT);

        for (;;) {
                if (lex.type() == TOK_LT) {
                        if (lex.peek().type() == TOK_SLASH)
                                break;
                }
                n->add_kid(parse(lex));
        }

        nodes.push_back(n);
        return n;
}

void node_free(node* n)
{
        for (auto node : nodes) {
                delete node;
        }
}

node *parse_html_tag(lexer& lex)
{
        auto n = new html_node{};
        lex.skip(TOK_HTML);
        lex.skip(TOK_GT);

        for (;;) {
                if (lex.type() == TOK_LT) {
                        if (lex.peek().type() == TOK_SLASH)
                                break;
                }
                n->add_kid(parse(lex));
        }

        nodes.push_back(n);
        return n;
}

node *parse_body_tag(lexer& lex)
{
        auto n = new body_node{};
        lex.skip(TOK_BODY);
        lex.skip(TOK_GT);

        for (;;) {
                if (lex.type() == TOK_LT) {
                        if (lex.peek().type() == TOK_SLASH)
                                break;
                }
                n->add_kid(parse(lex));
        }

        nodes.push_back(n);
        return n;
}
