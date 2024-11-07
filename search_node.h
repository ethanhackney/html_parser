#ifndef SEARCH_H
#define SEARCH_H

#include "node.h"

class search_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
