#include "cite_node.h"

void cite_node::visit(node_visitor* v)
{
	v->visit(this);
}
