#ifndef P_H
#define P_H

#include "node.h"

class p_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
