#include "p_node.h"

void p_node::visit(node_visitor* v)
{
        v->visit(this);
}
