#include "optgroup_node.h"

void optgroup_node::visit(node_visitor* v)
{
	v->visit(this);
}
