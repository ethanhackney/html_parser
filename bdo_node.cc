#include "bdo_node.h"

void bdo_node::visit(node_visitor* v)
{
	v->visit(this);
}
