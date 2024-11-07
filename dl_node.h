#ifndef DL_H
#define DL_H

#include "node.h"

class dl_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
