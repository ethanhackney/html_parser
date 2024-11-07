#include "canvas_node.h"

void canvas_node::visit(node_visitor* v)
{
	v->visit(this);
}
