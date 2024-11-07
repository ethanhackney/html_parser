#include "hgroup_node.h"

void hgroup_node::visit(node_visitor* v)
{
	v->visit(this);
}
