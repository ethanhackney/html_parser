#include "section_node.h"

void section_node::visit(node_visitor* v)
{
	v->visit(this);
}
