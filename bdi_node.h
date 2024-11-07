#ifndef BDI_H
#define BDI_H

#include "node.h"

class bdi_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
