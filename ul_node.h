#ifndef UL_H
#define UL_H

#include "node.h"

class ul_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
