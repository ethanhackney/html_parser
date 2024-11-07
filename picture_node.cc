#include "picture_node.h"

void picture_node::visit(node_visitor* v)
{
	v->visit(this);
}
