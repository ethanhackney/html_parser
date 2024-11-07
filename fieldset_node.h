#ifndef FIELDSET_H
#define FIELDSET_H

#include "node.h"

class fieldset_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
