#include "noscript_node.h"

void noscript_node::visit(node_visitor* v)
{
	v->visit(this);
}
