#include "br_node.h"

void br_node::visit(node_visitor* v)
{
	v->visit(this);
}
