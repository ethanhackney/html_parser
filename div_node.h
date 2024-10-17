#ifndef DIV_NODE_H
#define DIV_NODE_H

#include "node.h"

class div_node : public internal_node {
public:
        virtual void visit(node_visitor* v);
};

#endif
