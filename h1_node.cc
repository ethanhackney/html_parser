#include "h1_node.h"

void h1_node::visit(node_visitor* v)
{
	v->visit(this);
}
