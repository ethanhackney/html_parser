#include "caption_node.h"

void caption_node::visit(node_visitor* v)
{
	v->visit(this);
}
