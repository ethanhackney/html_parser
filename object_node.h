#ifndef OBJECT_H
#define OBJECT_H

#include "node.h"

class object_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
