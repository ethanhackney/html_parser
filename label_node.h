#ifndef LABEL_H
#define LABEL_H

#include "node.h"

class label_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
