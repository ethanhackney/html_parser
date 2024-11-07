#ifndef KBD_H
#define KBD_H

#include "node.h"

class kbd_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
