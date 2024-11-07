#ifndef EM_H
#define EM_H

#include "node.h"

class em_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
