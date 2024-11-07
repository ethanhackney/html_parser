#include "img_node.h"

void img_node::visit(node_visitor* v)
{
	v->visit(this);
}
