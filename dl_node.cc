#include "dl_node.h"

void dl_node::visit(node_visitor* v)
{
	v->visit(this);
}
