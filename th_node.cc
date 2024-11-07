#include "th_node.h"

void th_node::visit(node_visitor* v)
{
	v->visit(this);
}
