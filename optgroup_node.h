#ifndef OPTGROUP_H
#define OPTGROUP_H

#include "node.h"

class optgroup_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
