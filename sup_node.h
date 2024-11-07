#ifndef SUP_H
#define SUP_H

#include "node.h"

class sup_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
