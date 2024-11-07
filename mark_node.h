#ifndef MARK_H
#define MARK_H

#include "node.h"

class mark_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
