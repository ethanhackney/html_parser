#include "rp_node.h"

void rp_node::visit(node_visitor* v)
{
	v->visit(this);
}
