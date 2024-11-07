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

void dump_visitor::dump_internal_node(const std::string& name, internal_node* n)
{
        indent(_indent);
        cout << name << "{\n";

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

void dump_visitor::visit(abbr_node* n)
{
	dump_internal_node("abbr_node", n);
}

void dump_visitor::visit(a_node* n)
{
	dump_internal_node("a_node", n);
}

void dump_visitor::visit(body_node* n)
{
	dump_internal_node("body_node", n);
}

void dump_visitor::visit(bold_node* n)
{
	dump_internal_node("bold_node", n);
}

void dump_visitor::visit(div_node* n)
{
	dump_internal_node("div_node", n);
}

void dump_visitor::visit(html_node* n)
{
	dump_internal_node("html_node", n);
}

void dump_visitor::visit(p_node* n)
{
	dump_internal_node("p_node", n);
}

void dump_visitor::visit(table_node* n)
{
	dump_internal_node("table_node", n);
}

void dump_visitor::visit(area_node* n)
{
	dump_internal_node("area_node", n);
}

void dump_visitor::visit(article_node* n)
{
	dump_internal_node("article_node", n);
}

void dump_visitor::visit(aside_node* n)
{
	dump_internal_node("aside_node", n);
}

void dump_visitor::visit(audio_node* n)
{
	dump_internal_node("audio_node", n);
}

void dump_visitor::visit(b_node* n)
{
	dump_internal_node("b_node", n);
}

void dump_visitor::visit(base_node* n)
{
	dump_internal_node("base_node", n);
}

void dump_visitor::visit(bdi_node* n)
{
	dump_internal_node("bdi_node", n);
}

void dump_visitor::visit(bdo_node* n)
{
	dump_internal_node("bdo_node", n);
}

void dump_visitor::visit(blockquote_node* n)
{
	dump_internal_node("blockquote_node", n);
}

void dump_visitor::visit(br_node* n)
{
	dump_internal_node("br_node", n);
}

void dump_visitor::visit(button_node* n)
{
	dump_internal_node("button_node", n);
}

void dump_visitor::visit(canvas_node* n)
{
	dump_internal_node("canvas_node", n);
}

void dump_visitor::visit(caption_node* n)
{
	dump_internal_node("caption_node", n);
}

