#include "u_node.h"

void u_node::visit(node_visitor* v)
{
	v->visit(this);
}
