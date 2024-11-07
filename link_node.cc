#include "link_node.h"

void link_node::visit(node_visitor* v)
{
	v->visit(this);
}
