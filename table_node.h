#ifndef TABLE_NODE_H
#define TABLE_NODE_H

#include "node.h"

class table_node : public internal_node {
public:
        virtual void visit(node_visitor* v);
};

#endif
