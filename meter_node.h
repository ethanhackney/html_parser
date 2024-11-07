#ifndef METER_H
#define METER_H

#include "node.h"

class meter_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
