#ifndef SMALL_H
#define SMALL_H

#include "node.h"

class small_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
