#ifndef SUMMARY_H
#define SUMMARY_H

#include "node.h"

class summary_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
