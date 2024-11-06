#ifndef TABLE_H
#define TABLE_H

#include "node.h"

class table_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
