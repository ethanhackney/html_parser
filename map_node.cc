#include "map_node.h"

void map_node::visit(node_visitor* v)
{
	v->visit(this);
}
