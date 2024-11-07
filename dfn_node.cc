#include "dfn_node.h"

void dfn_node::visit(node_visitor* v)
{
	v->visit(this);
}
