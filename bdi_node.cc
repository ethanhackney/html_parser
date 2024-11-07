#include "bdi_node.h"

void bdi_node::visit(node_visitor* v)
{
	v->visit(this);
}
