#include "head_node.h"

void head_node::visit(node_visitor* v)
{
	v->visit(this);
}
