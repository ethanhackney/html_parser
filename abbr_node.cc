#include "abbr_node.h"

void abbr_node::visit(node_visitor* v)
{
	v->visit(this);
}
