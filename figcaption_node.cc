#include "figcaption_node.h"

void figcaption_node::visit(node_visitor* v)
{
	v->visit(this);
}
