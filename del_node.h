#ifndef DEL_H
#define DEL_H

#include "node.h"

class del_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
