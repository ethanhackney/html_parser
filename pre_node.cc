#include "pre_node.h"

void pre_node::visit(node_visitor* v)
{
	v->visit(this);
}
