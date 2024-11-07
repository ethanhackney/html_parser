#include "details_node.h"

void details_node::visit(node_visitor* v)
{
	v->visit(this);
}
