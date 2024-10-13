#ifndef NODE_H
#define NODE_H

#include "node_visitor.h"
#include <string>
#include <unordered_map>
#include <vector>

class node {
public:
        virtual void add_kid(node* n) = 0;
        virtual node* get_kid(size_t i) = 0;
        virtual void set_attr(std::string attr, std::string v) = 0;
        virtual std::string get_attr(std::string attr) = 0;
        virtual std::unordered_map<std::string,std::string>& attrs(void) = 0;
        virtual std::vector<node*>& kids(void) = 0;
        virtual void visit(node_visitor* v) = 0;
        virtual ~node() {}
};

class internal_node : public node {
private:
        std::unordered_map<std::string,std::string> _attrs;
        std::vector<node*> _kids;
public:
        virtual void add_kid(node* n);
        virtual node* get_kid(size_t i);
        virtual void set_attr(std::string attr, std::string v);
        virtual std::string get_attr(std::string attr);
        virtual std::unordered_map<std::string,std::string>& attrs(void);
        virtual std::vector<node*>& kids(void);
        virtual ~internal_node();
};

#endif
