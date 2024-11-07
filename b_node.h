#ifndef B_H
#define B_H

#include "node.h"

class b_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
