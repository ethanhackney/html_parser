#ifndef HEAD_H
#define HEAD_H

#include "node.h"

class head_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
