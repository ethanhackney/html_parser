#ifndef DATA_H
#define DATA_H

#include "node.h"

class data_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
