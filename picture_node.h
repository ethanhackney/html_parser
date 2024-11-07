#ifndef PICTURE_H
#define PICTURE_H

#include "node.h"

class picture_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
