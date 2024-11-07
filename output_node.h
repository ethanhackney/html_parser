#ifndef OUTPUT_H
#define OUTPUT_H

#include "node.h"

class output_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
