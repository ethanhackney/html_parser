#ifndef MAP_H
#define MAP_H

#include "node.h"

class map_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
