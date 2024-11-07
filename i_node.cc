#include "i_node.h"

void i_node::visit(node_visitor* v)
{
	v->visit(this);
}
