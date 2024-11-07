#include "menu_node.h"

void menu_node::visit(node_visitor* v)
{
	v->visit(this);
}
