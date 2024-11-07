#include "tfoot_node.h"

void tfoot_node::visit(node_visitor* v)
{
	v->visit(this);
}
