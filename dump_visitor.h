#ifndef DUMP_VISITOR_H
#define DUMP_VISITOR_H

#include "a_node.h"
#include "bold_node.h"
#include "html_node.h"
#include "node_visitor.h"
#include "p_node.h"
#include "text_node.h"
#include "body_node.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class dump_visitor : public node_visitor {
private:
        int _indent {0};

        void dump_attrs(std::unordered_map<std::string,std::string>& attrs);
        void dump_kids(std::vector<node*>& kids);
        void indent(int space);
public:
        virtual void visit(text_node* n);
        virtual void visit(a_node* n);
        virtual void visit(bold_node* n);
        virtual void visit(html_node* n);
        virtual void visit(p_node* n);
        virtual void visit(body_node* n);
};

#endif
