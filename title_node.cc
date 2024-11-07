#include "title_node.h"

void title_node::visit(node_visitor* v)
{
	v->visit(this);
}
