#ifndef TH_H
#define TH_H

#include "node.h"

class th_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
