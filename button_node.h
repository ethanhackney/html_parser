#ifndef BUTTON_H
#define BUTTON_H

#include "node.h"

class button_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
