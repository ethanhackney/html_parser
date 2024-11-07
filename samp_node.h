#ifndef SAMP_H
#define SAMP_H

#include "node.h"

class samp_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
