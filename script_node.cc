#include "script_node.h"

void script_node::visit(node_visitor* v)
{
	v->visit(this);
}
