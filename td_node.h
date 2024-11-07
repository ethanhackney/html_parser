#ifndef TD_H
#define TD_H

#include "node.h"

class td_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
