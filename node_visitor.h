#ifndef NODE_VISITOR_H
#define NODE_VISITOR_H

class text_node;
class abbr_node;
class a_node;
class body_node;
class bold_node;
class div_node;
class html_node;
class p_node;
class table_node;
class area_node;
class article_node;
class aside_node;
class audio_node;
class b_node;
class base_node;
class bdi_node;
class bdo_node;
class blockquote_node;
class br_node;
class button_node;
class canvas_node;
class caption_node;

class node_visitor {
public:
	virtual void visit(text_node* n) = 0;
	virtual void visit(abbr_node* n) = 0;
	virtual void visit(a_node* n) = 0;
	virtual void visit(body_node* n) = 0;
	virtual void visit(bold_node* n) = 0;
	virtual void visit(div_node* n) = 0;
	virtual void visit(html_node* n) = 0;
	virtual void visit(p_node* n) = 0;
	virtual void visit(table_node* n) = 0;
	virtual void visit(area_node* n) = 0;
	virtual void visit(article_node* n) = 0;
	virtual void visit(aside_node* n) = 0;
	virtual void visit(audio_node* n) = 0;
	virtual void visit(b_node* n) = 0;
	virtual void visit(base_node* n) = 0;
	virtual void visit(bdi_node* n) = 0;
	virtual void visit(bdo_node* n) = 0;
	virtual void visit(blockquote_node* n) = 0;
	virtual void visit(br_node* n) = 0;
	virtual void visit(button_node* n) = 0;
	virtual void visit(canvas_node* n) = 0;
	virtual void visit(caption_node* n) = 0;
	virtual ~node_visitor() {}
};

#endif
