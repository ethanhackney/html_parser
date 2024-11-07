#include "var_node.h"

void var_node::visit(node_visitor* v)
{
	v->visit(this);
}
