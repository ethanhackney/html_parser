#ifndef CAPTION_H
#define CAPTION_H

#include "node.h"

class caption_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
