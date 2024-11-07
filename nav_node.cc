#include "nav_node.h"

void nav_node::visit(node_visitor* v)
{
	v->visit(this);
}
