#include "progress_node.h"

void progress_node::visit(node_visitor* v)
{
	v->visit(this);
}
