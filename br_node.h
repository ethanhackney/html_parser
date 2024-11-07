#ifndef BR_H
#define BR_H

#include "node.h"

class br_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
