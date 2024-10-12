#include "lexer.h"
#include "token.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using std::cout;

class text_node;
class a_node;
class bold_node;

class node_visitor {
public:
        virtual void visit(text_node* n) = 0;
        virtual void visit(a_node* n) = 0;
        virtual void visit(bold_node* n) = 0;
        virtual ~node_visitor() {}
};

class node {
public:
        virtual void add_kid(node* n) = 0;
        virtual node* get_kid(size_t i) = 0;
        virtual void set_attr(std::string attr, std::string v) = 0;
        virtual std::string get_attr(std::string attr) = 0;
        virtual std::unordered_map<std::string,std::string>& attrs(void) = 0;
        virtual std::vector<node*>& kids(void) = 0;
        virtual void visit(node_visitor* v) = 0;
        virtual ~node() {}
};

class internal_node : public node {
private:
        std::unordered_map<std::string,std::string> _attrs;
        std::vector<node*> _kids;
public:
        virtual void add_kid(node* n);
        virtual node* get_kid(size_t i);
        virtual void set_attr(std::string attr, std::string v);
        virtual std::string get_attr(std::string attr);
        virtual std::unordered_map<std::string,std::string>& attrs(void);
        virtual std::vector<node*>& kids(void);
        virtual ~internal_node();
};

internal_node::~internal_node()
{
        for (auto k : _kids)
                delete k;
}

void internal_node::add_kid(node* n)
{
        _kids.push_back(n);
}

node* internal_node::get_kid(size_t i)
{
        return _kids.at(i);
}

void internal_node::set_attr(std::string attr, std::string v)
{
        _attrs[attr] = v;
}

std::string internal_node::get_attr(std::string attr)
{
        return _attrs[attr];
}

std::unordered_map<std::string,std::string>& internal_node::attrs(void)
{
        return _attrs;
}

std::vector<node*>& internal_node::kids(void)
{
        return _kids;
}

class text_node : public node {
private:
        int _c;
public:
        text_node(int c);
        virtual void visit(node_visitor* v);
        int c(void);
        virtual void add_kid(node* n);
        virtual node* get_kid(size_t i);
        virtual void set_attr(std::string attr, std::string v);
        virtual std::string get_attr(std::string attr);
        virtual std::unordered_map<std::string,std::string>& attrs(void);
        virtual std::vector<node*>& kids(void);
};

text_node::text_node(int c)
        : _c {c}
{}

void text_node::visit(node_visitor* n)
{
        n->visit(this);
}

int text_node::c(void)
{
        return _c;
}

void text_node::add_kid(node* n)
{
}

node* text_node::get_kid(size_t i)
{
        return nullptr;
}

void text_node::set_attr(std::string attr, std::string v)
{
}

std::string text_node::get_attr(std::string attr)
{
        return "";
}

std::unordered_map<std::string,std::string>& text_node::attrs(void)
{
        static std::unordered_map<std::string,std::string> nil;
        return nil;
}

std::vector<node*>& text_node::kids(void)
{
        static std::vector<node*> nil;
        return nil;
}

class a_node : public internal_node {
public:
        virtual void visit(node_visitor* v);
};

void a_node::visit(node_visitor* v)
{
        v->visit(this);
}

class bold_node : public internal_node {
public:
        virtual void visit(node_visitor* v);
};

void bold_node::visit(node_visitor* v)
{
        v->visit(this);
}

class dump_visitor : public node_visitor {
private:
        int _indent {0};

        void dump_attrs(std::unordered_map<std::string,std::string>& attrs);
        void dump_kids(std::vector<node*>& kids);
        void indent(int space);
public:
        virtual void visit(text_node* n);
        virtual void visit(a_node* n);
        virtual void visit(bold_node* n);
};

void dump_visitor::indent(int space)
{
        for (auto i = 0; i < space; i++)
                cout << " ";
}

void dump_visitor::visit(text_node* n)
{
        indent(_indent);
        cout << "text_node{\n";
        indent(_indent + 2);
        cout << '"' << (char)n->c() << "\"\n";
        indent(_indent);
        cout << "}";
}

void dump_visitor::dump_attrs(std::unordered_map<std::string,std::string>& attrs)
{
        indent(_indent);
        cout << "attrs: {\n";
        for (auto p : attrs) {
                indent(_indent + 2);
                cout << p.first << ": " << p.second << ",\n";
        }
        indent(_indent);
        cout << "}";
}

void dump_visitor::dump_kids(std::vector<node*>& kids)
{
        indent(_indent);
        cout << "kids: [\n";
        for (auto k : kids) {
                _indent += 2;
                k->visit(this);
                cout << ",\n";
                _indent -= 2;

        }
        indent(_indent);
        cout << "]";
}

void dump_visitor::visit(a_node* n)
{
        indent(_indent);
        cout << "a_node{\n";

        _indent += 2;
        dump_attrs(n->attrs());
        _indent -= 2;
        cout << ",\n";

        _indent += 2;
        dump_kids(n->kids());
        _indent -= 2;
        cout << "\n";

        indent(_indent);
        cout << "}";
}

void dump_visitor::visit(bold_node* n)
{
        indent(_indent);
        cout << "bold_node{\n";

        _indent += 2;
        dump_attrs(n->attrs());
        _indent -= 2;
        cout << ",\n";

        _indent += 2;
        dump_kids(n->kids());
        _indent -= 2;
        cout << "\n";

        indent(_indent);
        cout << "}";
}

class parser {
private:
        lexer& _lex;
        std::vector<node*> _roots;

        node* do_parse(void);
        node* parse_tag(void);
        node* parse_a_tag(void);
public:
        parser(lexer& lex);
        void parse(void);
        int eof(void);
        node* get_root(size_t i);
        size_t n_roots(void);
        ~parser();
};

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
        } else {
                errno = EINVAL;
                err(EX_USAGE, "invalid tagname: %s", token{type}.name().c_str());
        }

        while (_lex.type() != TOK_GT) {
                auto attr = _lex.lex();
                _lex.skip(_lex.type());
                _lex.skip(TOK_EQ);
                auto v = _lex.lex();
                _lex.skip(_lex.type());
                n->set_attr(attr, v);
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

int main(void)
{
        lexer l {"index.html"};
        parser p {l};

        p.parse();

        node_visitor* dv = new dump_visitor{};
        for (size_t r = 0; r < p.n_roots(); r++) {
                p.get_root(r)->visit(dv);
                cout << "\n";
        }

        delete dv;
}
