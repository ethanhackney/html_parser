#include "samp_node.h"

void samp_node::visit(node_visitor* v)
{
	v->visit(this);
}
