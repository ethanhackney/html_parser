#ifndef CITE_H
#define CITE_H

#include "node.h"

class cite_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
