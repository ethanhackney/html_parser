#ifndef SELECT_H
#define SELECT_H

#include "node.h"

class select_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
