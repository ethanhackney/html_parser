#include "output_node.h"

void output_node::visit(node_visitor* v)
{
	v->visit(this);
}
