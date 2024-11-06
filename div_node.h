#ifndef DIV_H
#define DIV_H

#include "node.h"

class div_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
