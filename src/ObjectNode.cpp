#include "ObjectNode.hpp"

std::string ObjectNode::print() const
{
    std::string result = "{";
    bool        first  = true;
    for (auto const& el : _data)
    {
        if (first)
            first = false;
        else
            result += ",";
        result += '"' + el.first + "\":";
        result += el.second->print();
    }
    result += '}';
    return result;
}

std::unique_ptr<ObjectNode> ObjectNode::make_ptr(std::map<std::string, NodePtr> data)
{
    auto result   = std::make_unique<ObjectNode>();
    result->_data = std::move(data);
    return result;
}

size_t ObjectNode::height() const
{
    if (this->child_count() == 0)
        return 0u;
    size_t result = 0;
    for (const auto& child : _data)
    {
        size_t child_height = child.second->height();
        if (child_height > result)
            result = child_height;
    }
    return result + 1;
}

size_t ObjectNode::node_count() const
{
    size_t result = 1;
    for (const auto& child : _data)
    {
        result += child.second->node_count();
    }
    return result;
}

Node* ObjectNode::at(const std::string& key)
{
    if (has_child(key))
        return _data.at(key).get();
    else
        return nullptr;
}

const Node* ObjectNode::at(std::string const& key) const
{
    if (has_child(key))
        return _data.at(key).get();
    else
        return nullptr;
}

NodePtr ObjectNode::deep_copy() const
{
    auto result = make_ptr();
    for (auto const& [key, child] : this->data())
        result->insert(key, child->deep_copy());
    return result;
}

void ObjectNode::dot(std::ostream& o) const
{
    o << "subgraph cluster_" << dot_id() << " {style=invis;" << std::endl;
    Node::dot(o);
    for (auto& [k, v] : _data)
    {
        v->dot(o);
        o << dot_id() << " -> " << v->dot_id() << " [label= \"" << k << "\"];" << std::endl;
    }
    o << "}" << std::endl;
}

bool ObjectNode::operator==(const Node& other) const
{
    if (other.kind() != kind())
        return false;

    ObjectNode const* other_s = other.as_ObjectNode();
    if (other_s->child_count() != this->child_count())
        return false;
    for (auto& pair : other_s->_data)
    {
        auto it = _data.find(pair.first);
        if (it == _data.end())
            return false;
        if (!(*(it->second) == *(pair.second)))
            return false;
    }
    return true;
}