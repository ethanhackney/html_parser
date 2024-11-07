#include "label_node.h"

void label_node::visit(node_visitor* v)
{
	v->visit(this);
}
