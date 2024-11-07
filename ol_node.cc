#include "ol_node.h"

void ol_node::visit(node_visitor* v)
{
	v->visit(this);
}
