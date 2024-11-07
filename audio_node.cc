#include "audio_node.h"

void audio_node::visit(node_visitor* v)
{
	v->visit(this);
}
