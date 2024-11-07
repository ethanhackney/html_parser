#include "summary_node.h"

void summary_node::visit(node_visitor* v)
{
	v->visit(this);
}
