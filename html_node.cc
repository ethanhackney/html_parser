#include "html_node.h"

html_node::html_node(void)
{
        set_attr("xmlns", "http://www.w3.org/1999/xhtml");
}

void html_node::visit(node_visitor* v)
{
        v->visit(this);
}
