#include "rt_node.h"

void rt_node::visit(node_visitor* v)
{
	v->visit(this);
}
