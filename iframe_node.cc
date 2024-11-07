#include "iframe_node.h"

void iframe_node::visit(node_visitor* v)
{
	v->visit(this);
}
