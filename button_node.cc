#include "button_node.h"

void button_node::visit(node_visitor* v)
{
	v->visit(this);
}
