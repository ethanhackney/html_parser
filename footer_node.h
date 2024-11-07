#ifndef FOOTER_H
#define FOOTER_H

#include "node.h"

class footer_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
