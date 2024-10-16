#ifndef BODY_NODE_H
#define BODY_NODE_H

#include "node.h"

class body_node : public internal_node {
public:
        virtual void visit(node_visitor* v);
};

#endif
