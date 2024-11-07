#ifndef RP_H
#define RP_H

#include "node.h"

class rp_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
