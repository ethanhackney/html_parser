#include "wbr_node.h"

void wbr_node::visit(node_visitor* v)
{
	v->visit(this);
}
