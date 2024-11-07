#include "ruby_node.h"

void ruby_node::visit(node_visitor* v)
{
	v->visit(this);
}
