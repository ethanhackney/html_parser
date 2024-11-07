#ifndef NOSCRIPT_H
#define NOSCRIPT_H

#include "node.h"

class noscript_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
