#include "slot_node.h"

void slot_node::visit(node_visitor* v)
{
	v->visit(this);
}
