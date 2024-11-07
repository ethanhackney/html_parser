#include "td_node.h"

void td_node::visit(node_visitor* v)
{
	v->visit(this);
}
