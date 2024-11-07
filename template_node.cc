#include "template_node.h"

void template_node::visit(node_visitor* v)
{
	v->visit(this);
}
