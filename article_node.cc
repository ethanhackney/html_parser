#include "article_node.h"

void article_node::visit(node_visitor* v)
{
	v->visit(this);
}
