#ifndef THEAD_H
#define THEAD_H

#include "node.h"

class thead_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
