#include "datalist_node.h"

void datalist_node::visit(node_visitor* v)
{
	v->visit(this);
}
