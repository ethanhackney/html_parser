#ifndef TITLE_H
#define TITLE_H

#include "node.h"

class title_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
