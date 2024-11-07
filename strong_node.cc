#include "strong_node.h"

void strong_node::visit(node_visitor* v)
{
	v->visit(this);
}
