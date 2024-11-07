#ifndef H1_H
#define H1_H

#include "node.h"

class h1_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
