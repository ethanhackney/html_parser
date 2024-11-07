#ifndef DFN_H
#define DFN_H

#include "node.h"

class dfn_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
