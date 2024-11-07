#ifndef HEADER_H
#define HEADER_H

#include "node.h"

class header_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
