#ifndef EMBED_H
#define EMBED_H

#include "node.h"

class embed_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
