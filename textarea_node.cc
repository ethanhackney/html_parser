#include "textarea_node.h"

void textarea_node::visit(node_visitor* v)
{
	v->visit(this);
}
