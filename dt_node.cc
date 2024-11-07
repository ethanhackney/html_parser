#include "dt_node.h"

void dt_node::visit(node_visitor* v)
{
	v->visit(this);
}
