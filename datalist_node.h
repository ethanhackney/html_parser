#ifndef DATALIST_H
#define DATALIST_H

#include "node.h"

class datalist_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
