#ifndef FIGURE_H
#define FIGURE_H

#include "node.h"

class figure_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
