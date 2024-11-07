#ifndef INPUT_H
#define INPUT_H

#include "node.h"

class input_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
