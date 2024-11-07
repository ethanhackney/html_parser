#include "track_node.h"

void track_node::visit(node_visitor* v)
{
	v->visit(this);
}
