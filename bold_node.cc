#include "bold_node.h"

void bold_node::visit(node_visitor* v)
{
	v->visit(this);
}
