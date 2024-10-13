#include "dump_visitor.h"

using std::cout;

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

void dump_visitor::visit(html_node* n)
{
        indent(_indent);
        cout << "html_node{\n";

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
