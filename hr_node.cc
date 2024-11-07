#include "hr_node.h"

void hr_node::visit(node_visitor* v)
{
	v->visit(this);
}
