#ifndef SUB_H
#define SUB_H

#include "node.h"

class sub_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
