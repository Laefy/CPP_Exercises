#include "IntLeaf.hpp"

bool IntLeaf::operator==(const Node& other) const
{
    if (other.kind() != kind())
    {
        return false;
    }
    return (_data == other.as_IntLeaf()->_data);
}

std::unique_ptr<IntLeaf> IntLeaf::make_ptr(int data)
{
    return std::make_unique<IntLeaf>(data);
}