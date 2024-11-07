#ifndef INS_H
#define INS_H

#include "node.h"

class ins_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
