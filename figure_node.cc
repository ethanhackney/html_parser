#include "figure_node.h"

void figure_node::visit(node_visitor* v)
{
	v->visit(this);
}
