#include "ArrayNode.hpp"

std::string ArrayNode::print() const
{
    std::string result = "[";
    for (unsigned i = 0; i < _data.size(); ++i)
    {
        if (i > 0)
            result += ",";
        result += _data[i]->print();
    }
    result += ']';
    return result;
}

void ArrayNode::push_back(NodePtr node)
{
    _data.push_back(std::move(node));
}

std::unique_ptr<ArrayNode> ArrayNode::make_ptr(std::vector<NodePtr> data)
{
    auto result   = std::make_unique<ArrayNode>();
    result->_data = std::move(data);
    return result;
}

size_t ArrayNode::height() const
{
    if (this->child_count() == 0)
        return 0u;
    size_t result = 0;
    for (const auto& child : _data)
    {
        size_t child_height = child->height();
        if (child_height > result)
            result = child_height;
    }
    return result + 1;
}

size_t ArrayNode::node_count() const
{
    size_t result = 1;
    for (const auto& child : _data)
    {
        result += child->node_count();
    }
    return result;
}

bool ArrayNode::operator==(const Node& other) const
{
    if (other.kind() != kind())
    {
        std::cerr << kind() << "!=" << other.kind() << std::endl;
        return false;
    }
    ArrayNode const* other_s = other.as_ArrayNode();
    size_t           size    = child_count();
    if (other_s->child_count() != size)
    {
        std::cerr << size << " != " << other_s->child_count() << std::endl;
        return false;
    }
    for (unsigned i = 0; i < size; i++)
    {
        if (!(*(other_s->_data[i]) == *(_data[i])))
        {
            std::cerr << *(other_s->_data[i]) << std::endl;
            std::cerr << *_data[i] << std::endl;
            return false;
        }
    }
    return true;
}

NodePtr ArrayNode::deep_copy() const
{
    auto result = make_ptr();
    for (auto const& elt : this->_data)
        result->push_back(elt->deep_copy());
    return result;
}

void ArrayNode::dot(std::ostream& o) const
{
    Node::dot(o);
    o << "subgraph cluster_" << dot_id() << " {style=invis;" << std::endl;
    for (auto it = _data.rbegin(); it != _data.rend(); ++it)
    {
        (*it)->dot(o);
        o << dot_id() << " -> " << (*it)->dot_id() << " ;" << std::endl;
    }
    o << "}" << std::endl;
}
