#ifndef BOLD_H
#define BOLD_H

#include "node.h"

class bold_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
