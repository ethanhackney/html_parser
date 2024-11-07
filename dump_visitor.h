#ifndef DUMP_VISITOR_H
#define DUMP_VISITOR_H

#include "text_node.h"
#include "abbr_node.h"
#include "a_node.h"
#include "body_node.h"
#include "bold_node.h"
#include "div_node.h"
#include "html_node.h"
#include "p_node.h"
#include "table_node.h"
#include "area_node.h"
#include "article_node.h"
#include "aside_node.h"
#include "audio_node.h"
#include "b_node.h"
#include "base_node.h"
#include "bdi_node.h"
#include "bdo_node.h"
#include "blockquote_node.h"
#include "br_node.h"
#include "button_node.h"
#include "canvas_node.h"
#include "caption_node.h"

#include "node_visitor.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class dump_visitor : public node_visitor {
private:
        int _indent {0};

        void dump_attrs(std::unordered_map<std::string,std::string>& attrs);
        void dump_kids(std::vector<node*>& kids);
        void dump_internal_node(const std::string& name, internal_node* n);
        void indent(int space);
public:
        virtual void visit(text_node* n);
	virtual void visit(abbr_node* n);
	virtual void visit(a_node* n);
	virtual void visit(body_node* n);
	virtual void visit(bold_node* n);
	virtual void visit(div_node* n);
	virtual void visit(html_node* n);
	virtual void visit(p_node* n);
	virtual void visit(table_node* n);
	virtual void visit(area_node* n);
	virtual void visit(article_node* n);
	virtual void visit(aside_node* n);
	virtual void visit(audio_node* n);
	virtual void visit(b_node* n);
	virtual void visit(base_node* n);
	virtual void visit(bdi_node* n);
	virtual void visit(bdo_node* n);
	virtual void visit(blockquote_node* n);
	virtual void visit(br_node* n);
	virtual void visit(button_node* n);
	virtual void visit(canvas_node* n);
	virtual void visit(caption_node* n);
};

#endif
