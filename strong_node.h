#ifndef STRONG_H
#define STRONG_H

#include "node.h"

class strong_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
