#include "base_node.h"

void base_node::visit(node_visitor* v)
{
	v->visit(this);
}
