#ifndef DIALOG_H
#define DIALOG_H

#include "node.h"

class dialog_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
