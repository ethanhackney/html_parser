#include "option_node.h"

void option_node::visit(node_visitor* v)
{
	v->visit(this);
}
