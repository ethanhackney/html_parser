#include "kbd_node.h"

void kbd_node::visit(node_visitor* v)
{
	v->visit(this);
}
