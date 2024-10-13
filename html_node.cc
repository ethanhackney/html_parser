#include "html_node.h"

void html_node::visit(node_visitor* v)
{
        v->visit(this);
}
