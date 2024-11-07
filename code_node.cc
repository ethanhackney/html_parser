#include "code_node.h"

void code_node::visit(node_visitor* v)
{
	v->visit(this);
}
