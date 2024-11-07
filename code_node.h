#ifndef CODE_H
#define CODE_H

#include "node.h"

class code_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
