#ifndef COL_H
#define COL_H

#include "node.h"

class col_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
