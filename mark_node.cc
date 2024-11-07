#include "mark_node.h"

void mark_node::visit(node_visitor* v)
{
	v->visit(this);
}
