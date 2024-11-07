#ifndef LINK_H
#define LINK_H

#include "node.h"

class link_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
