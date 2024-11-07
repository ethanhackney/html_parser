#ifndef PRE_H
#define PRE_H

#include "node.h"

class pre_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
