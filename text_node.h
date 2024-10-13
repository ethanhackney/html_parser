#ifndef TEXT_NODE_H
#define TEXT_NODE_H

#include "node.h"

class text_node : public node {
private:
        int _c;
public:
        text_node(int c);
        virtual void visit(node_visitor* v);
        int c(void);
        virtual void add_kid(node* n);
        virtual node* get_kid(size_t i);
        virtual void set_attr(std::string attr, std::string v);
        virtual std::string get_attr(std::string attr);
        virtual std::unordered_map<std::string,std::string>& attrs(void);
        virtual std::vector<node*>& kids(void);
};

#endif
