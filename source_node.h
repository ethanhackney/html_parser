#ifndef SOURCE_H
#define SOURCE_H

#include "node.h"

class source_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
