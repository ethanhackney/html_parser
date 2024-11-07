#include "sub_node.h"

void sub_node::visit(node_visitor* v)
{
	v->visit(this);
}
