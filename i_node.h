#ifndef I_H
#define I_H

#include "node.h"

class i_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
