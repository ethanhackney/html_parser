#include "li_node.h"

void li_node::visit(node_visitor* v)
{
	v->visit(this);
}
