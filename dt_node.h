#ifndef DT_H
#define DT_H

#include "node.h"

class dt_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
