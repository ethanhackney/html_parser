#ifndef HTML_NODE_H
#define HTML_NODE_H

#include "node.h"

class html_node : public internal_node {
public:
        html_node(void);
        virtual void visit(node_visitor* v);
};

#endif
