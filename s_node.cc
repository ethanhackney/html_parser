#include "s_node.h"

void s_node::visit(node_visitor* v)
{
	v->visit(this);
}
