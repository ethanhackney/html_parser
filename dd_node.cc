#include "dd_node.h"

void dd_node::visit(node_visitor* v)
{
	v->visit(this);
}
