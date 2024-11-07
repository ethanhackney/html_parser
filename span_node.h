#ifndef SPAN_H
#define SPAN_H

#include "node.h"

class span_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
