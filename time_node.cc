#include "time_node.h"

void time_node::visit(node_visitor* v)
{
	v->visit(this);
}
