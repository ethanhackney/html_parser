#ifndef SLOT_H
#define SLOT_H

#include "node.h"

class slot_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
