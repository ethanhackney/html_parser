#ifndef STYLE_H
#define STYLE_H

#include "node.h"

class style_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
