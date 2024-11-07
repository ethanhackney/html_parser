#ifndef BASE_H
#define BASE_H

#include "node.h"

class base_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
