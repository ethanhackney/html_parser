#ifndef TIME_H
#define TIME_H

#include "node.h"

class time_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
