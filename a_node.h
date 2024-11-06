#ifndef A_H
#define A_H

#include "node.h"

class a_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
