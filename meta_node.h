#ifndef META_H
#define META_H

#include "node.h"

class meta_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
