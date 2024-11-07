#ifndef Q_H
#define Q_H

#include "node.h"

class q_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
