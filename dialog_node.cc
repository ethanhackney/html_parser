#include "dialog_node.h"

void dialog_node::visit(node_visitor* v)
{
	v->visit(this);
}
