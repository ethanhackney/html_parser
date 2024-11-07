#ifndef IFRAME_H
#define IFRAME_H

#include "node.h"

class iframe_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
