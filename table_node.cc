#include "table_node.h"

void table_node::visit(node_visitor* v)
{
        v->visit(this);
}
