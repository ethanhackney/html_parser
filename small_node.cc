#include "small_node.h"

void small_node::visit(node_visitor* v)
{
	v->visit(this);
}
