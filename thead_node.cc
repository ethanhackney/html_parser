#include "thead_node.h"

void thead_node::visit(node_visitor* v)
{
	v->visit(this);
}
