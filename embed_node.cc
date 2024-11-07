#include "embed_node.h"

void embed_node::visit(node_visitor* v)
{
	v->visit(this);
}
