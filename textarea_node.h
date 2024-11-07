#ifndef TEXTAREA_H
#define TEXTAREA_H

#include "node.h"

class textarea_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
