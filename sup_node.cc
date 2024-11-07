#include "sup_node.h"

void sup_node::visit(node_visitor* v)
{
	v->visit(this);
}
