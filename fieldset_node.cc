#include "fieldset_node.h"

void fieldset_node::visit(node_visitor* v)
{
	v->visit(this);
}
