#ifndef SCRIPT_H
#define SCRIPT_H

#include "node.h"

class script_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
