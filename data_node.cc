#include "data_node.h"

void data_node::visit(node_visitor* v)
{
	v->visit(this);
}
