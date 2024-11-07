#ifndef RT_H
#define RT_H

#include "node.h"

class rt_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
