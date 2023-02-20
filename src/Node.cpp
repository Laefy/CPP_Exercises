#include "Node.hpp"

#include "ArrayNode.hpp"
#include "IntLeaf.hpp"
#include "ObjectNode.hpp"
#include "StringLeaf.hpp"

std::ostream& operator<<(std::ostream& o, const Node& node)
{
    return o << node.print();
}

void Node::dot(std::ostream& o) const
{
    o << dot_id() << " [label=\"" << dot_label() << "\"];" << std::endl;
}

std::string Node::dot_id() const
{
    const void*       address = static_cast<const void*>(this);
    std::stringstream ss;
    ss << "n";
    ss << address;
    return ss.str();
}

IntLeaf* Node::as_IntLeaf()
{
    return dynamic_cast<IntLeaf*>(this);
}

StringLeaf* Node::as_StringLeaf()
{
    return dynamic_cast<StringLeaf*>(this);
}

ArrayNode* Node::as_ArrayNode()
{
    return dynamic_cast<ArrayNode*>(this);
}

ObjectNode* Node::as_ObjectNode()
{
    return dynamic_cast<ObjectNode*>(this);
}

const IntLeaf* Node::as_IntLeaf() const
{
    return dynamic_cast<const IntLeaf*>(this);
}

const StringLeaf* Node::as_StringLeaf() const
{
    return dynamic_cast<const StringLeaf*>(this);
}

const ArrayNode* Node::as_ArrayNode() const
{
    return dynamic_cast<const ArrayNode*>(this);
}

const ObjectNode* Node::as_ObjectNode() const
{
    return dynamic_cast<const ObjectNode*>(this);
}