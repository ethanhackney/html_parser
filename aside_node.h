#ifndef ASIDE_H
#define ASIDE_H

#include "node.h"

class aside_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
