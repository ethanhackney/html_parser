#ifndef OPTION_H
#define OPTION_H

#include "node.h"

class option_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
