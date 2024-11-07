#ifndef SECTION_H
#define SECTION_H

#include "node.h"

class section_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
