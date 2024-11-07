#include "b_node.h"

void b_node::visit(node_visitor* v)
{
	v->visit(this);
}
