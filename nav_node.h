#ifndef NAV_H
#define NAV_H

#include "node.h"

class nav_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
