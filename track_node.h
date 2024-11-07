#ifndef TRACK_H
#define TRACK_H

#include "node.h"

class track_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
