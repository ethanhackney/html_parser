#ifndef ARTICLE_H
#define ARTICLE_H

#include "node.h"

class article_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
