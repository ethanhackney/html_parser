#include "aside_node.h"

void aside_node::visit(node_visitor* v)
{
	v->visit(this);
}
