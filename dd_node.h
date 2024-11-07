#ifndef DD_H
#define DD_H

#include "node.h"

class dd_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
