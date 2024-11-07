#ifndef PROGRESS_H
#define PROGRESS_H

#include "node.h"

class progress_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
