#include "area_node.h"

void area_node::visit(node_visitor* v)
{
	v->visit(this);
}
