#ifndef MENU_H
#define MENU_H

#include "node.h"

class menu_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
