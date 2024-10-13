#include "node.h"

internal_node::~internal_node()
{
        for (auto k : _kids)
                delete k;
}

void internal_node::add_kid(node* n)
{
        _kids.push_back(n);
}

node* internal_node::get_kid(size_t i)
{
        return _kids.at(i);
}

void internal_node::set_attr(std::string attr, std::string v)
{
        _attrs[attr] = v;
}

std::string internal_node::get_attr(std::string attr)
{
        return _attrs[attr];
}

std::unordered_map<std::string,std::string>& internal_node::attrs(void)
{
        return _attrs;
}

std::vector<node*>& internal_node::kids(void)
{
        return _kids;
}
