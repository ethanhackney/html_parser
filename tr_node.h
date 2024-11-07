#ifndef TR_H
#define TR_H

#include "node.h"

class tr_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
