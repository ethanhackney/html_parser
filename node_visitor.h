#ifndef NODE_VISITOR_H
#define NODE_VISITOR_H

class a_node;
class bold_node;
class html_node;
class p_node;
class text_node;
class body_node;
class div_node;

class node_visitor {
public:
        virtual void visit(text_node* n) = 0;
        virtual void visit(a_node* n) = 0;
        virtual void visit(bold_node* n) = 0;
        virtual void visit(html_node* n) = 0;
        virtual void visit(p_node* n) = 0;
        virtual void visit(body_node* n) = 0;
        virtual void visit(div_node* n) = 0;
        virtual ~node_visitor() {}
};

#endif
