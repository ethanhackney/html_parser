#include "em_node.h"

void em_node::visit(node_visitor* v)
{
	v->visit(this);
}
