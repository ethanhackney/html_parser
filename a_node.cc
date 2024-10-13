#include "a_node.h"

void a_node::visit(node_visitor* v)
{
        v->visit(this);
}
