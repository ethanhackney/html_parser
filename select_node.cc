#include "select_node.h"

void select_node::visit(node_visitor* v)
{
	v->visit(this);
}
