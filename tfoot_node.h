#ifndef TFOOT_H
#define TFOOT_H

#include "node.h"

class tfoot_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
