#ifndef MAIN_H
#define MAIN_H

#include "node.h"

class main_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
