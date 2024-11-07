#include "form_node.h"

void form_node::visit(node_visitor* v)
{
	v->visit(this);
}
