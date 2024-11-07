#ifndef TBODY_H
#define TBODY_H

#include "node.h"

class tbody_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
