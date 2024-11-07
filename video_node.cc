#include "video_node.h"

void video_node::visit(node_visitor* v)
{
	v->visit(this);
}
