#ifndef FIGCAPTION_H
#define FIGCAPTION_H

#include "node.h"

class figcaption_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
