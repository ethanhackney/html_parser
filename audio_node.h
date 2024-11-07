#ifndef AUDIO_H
#define AUDIO_H

#include "node.h"

class audio_node : public internal_node {
public:
	virtual void visit(node_visitor* v);
};

#endif
