#include "body_node.h"

void body_node::visit(node_visitor* v)
{
        v->visit(this);
}
