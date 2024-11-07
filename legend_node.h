#ifndef LEGEND_H
#define LEGEND_H

#include "node.h"

class legend_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
