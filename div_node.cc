#include "div_node.h"

void div_node::visit(node_visitor* v)
{
	v->visit(this);
}
