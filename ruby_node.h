#ifndef RUBY_H
#define RUBY_H

#include "node.h"

class ruby_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
