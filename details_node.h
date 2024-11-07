#ifndef DETAILS_H
#define DETAILS_H

#include "node.h"

class details_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
