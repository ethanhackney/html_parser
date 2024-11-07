#ifndef OL_H
#define OL_H

#include "node.h"

class ol_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
