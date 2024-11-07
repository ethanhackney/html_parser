#include "tbody_node.h"

void tbody_node::visit(node_visitor* v)
{
	v->visit(this);
}
