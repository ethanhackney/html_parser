#ifndef VAR_H
#define VAR_H

#include "node.h"

class var_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
