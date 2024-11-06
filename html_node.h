#ifndef HTML_H
#define HTML_H

#include "node.h"

class html_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
