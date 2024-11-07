#ifndef CANVAS_H
#define CANVAS_H

#include "node.h"

class canvas_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
