#ifndef U_H
#define U_H

#include "node.h"

class u_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
