#include "header_node.h"

void header_node::visit(node_visitor* v)
{
	v->visit(this);
}
