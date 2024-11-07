#ifndef HR_H
#define HR_H

#include "node.h"

class hr_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
