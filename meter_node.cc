#include "meter_node.h"

void meter_node::visit(node_visitor* v)
{
	v->visit(this);
}
