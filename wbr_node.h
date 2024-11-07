#ifndef WBR_H
#define WBR_H

#include "node.h"

class wbr_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
