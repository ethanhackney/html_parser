#include "footer_node.h"

void footer_node::visit(node_visitor* v)
{
	v->visit(this);
}
