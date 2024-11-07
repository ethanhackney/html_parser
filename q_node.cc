#include "q_node.h"

void q_node::visit(node_visitor* v)
{
	v->visit(this);
}
