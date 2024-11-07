#include "input_node.h"

void input_node::visit(node_visitor* v)
{
	v->visit(this);
}
