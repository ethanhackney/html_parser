#ifndef VIDEO_H
#define VIDEO_H

#include "node.h"

class video_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
