#ifndef AREA_H
#define AREA_H

#include "node.h"

class area_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
