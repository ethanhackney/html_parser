#include "colgroup_node.h"

void colgroup_node::visit(node_visitor* v)
{
	v->visit(this);
}
