#include "search_node.h"

void search_node::visit(node_visitor* v)
{
	v->visit(this);
}
