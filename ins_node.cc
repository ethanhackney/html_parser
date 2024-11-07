#include "ins_node.h"

void ins_node::visit(node_visitor* v)
{
	v->visit(this);
}
