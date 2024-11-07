#include "legend_node.h"

void legend_node::visit(node_visitor* v)
{
	v->visit(this);
}
