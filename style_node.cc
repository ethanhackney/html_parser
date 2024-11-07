#include "style_node.h"

void style_node::visit(node_visitor* v)
{
	v->visit(this);
}
