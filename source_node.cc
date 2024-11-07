#include "source_node.h"

void source_node::visit(node_visitor* v)
{
	v->visit(this);
}
