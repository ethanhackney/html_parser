#ifndef LI_H
#define LI_H

#include "node.h"

class li_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
