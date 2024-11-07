#include "span_node.h"

void span_node::visit(node_visitor* v)
{
	v->visit(this);
}
