#include "del_node.h"

void del_node::visit(node_visitor* v)
{
	v->visit(this);
}
