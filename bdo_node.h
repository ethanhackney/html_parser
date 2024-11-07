#ifndef BDO_H
#define BDO_H

#include "node.h"

class bdo_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
