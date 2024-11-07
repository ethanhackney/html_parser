#include "blockquote_node.h"

void blockquote_node::visit(node_visitor* v)
{
	v->visit(this);
}
