#include "main_node.h"

void main_node::visit(node_visitor* v)
{
	v->visit(this);
}
