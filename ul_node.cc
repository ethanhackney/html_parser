#include "ul_node.h"

void ul_node::visit(node_visitor* v)
{
	v->visit(this);
}
