#include "tr_node.h"

void tr_node::visit(node_visitor* v)
{
	v->visit(this);
}
