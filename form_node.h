#ifndef FORM_H
#define FORM_H

#include "node.h"

class form_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
