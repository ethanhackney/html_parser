#ifndef S_H
#define S_H

#include "node.h"

class s_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
