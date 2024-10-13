#ifndef A_NODE_H
#define A_NODE_H

#include "node.h"

class a_node : public internal_node {
public:
        virtual void visit(node_visitor* v);
};

#endif
