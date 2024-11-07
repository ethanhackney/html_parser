#include "col_node.h"

void col_node::visit(node_visitor* v)
{
	v->visit(this);
}
