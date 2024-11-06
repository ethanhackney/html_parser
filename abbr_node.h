#ifndef ABBR_H
#define ABBR_H

#include "node.h"

class abbr_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
