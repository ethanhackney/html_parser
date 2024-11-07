#ifndef COLGROUP_H
#define COLGROUP_H

#include "node.h"

class colgroup_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
