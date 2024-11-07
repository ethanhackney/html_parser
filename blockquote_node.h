#ifndef BLOCKQUOTE_H
#define BLOCKQUOTE_H

#include "node.h"

class blockquote_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
