#include "object_node.h"

void object_node::visit(node_visitor* v)
{
	v->visit(this);
}
