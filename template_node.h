#ifndef TEMPLATE_H
#define TEMPLATE_H

#include "node.h"

class template_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
