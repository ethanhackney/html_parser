#include "text_node.h"

text_node::text_node(int c)
        : _c {c}
{}

void text_node::visit(node_visitor* n)
{
        n->visit(this);
}

int text_node::c(void)
{
        return _c;
}

void text_node::add_kid(node* n)
{
}

node* text_node::get_kid(size_t i)
{
        return nullptr;
}

void text_node::set_attr(std::string attr, std::string v)
{
}

std::string text_node::get_attr(std::string attr)
{
        return "";
}

std::unordered_map<std::string,std::string>& text_node::attrs(void)
{
        static std::unordered_map<std::string,std::string> nil;
        return nil;
}

std::vector<node*>& text_node::kids(void)
{
        static std::vector<node*> nil;
        return nil;
}
