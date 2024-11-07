#ifndef IMG_H
#define IMG_H

#include "node.h"

class img_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
