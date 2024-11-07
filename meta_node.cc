#include "meta_node.h"

void meta_node::visit(node_visitor* v)
{
	v->visit(this);
}
