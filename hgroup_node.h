#ifndef HGROUP_H
#define HGROUP_H

#include "node.h"

class hgroup_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
