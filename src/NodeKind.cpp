#include "NodeKind.hpp"

std::ostream& operator<<(std::ostream& o, NodeKind kind)
{
    switch (kind)
    {
    case NodeKind::INT:
        return o << "INT";
    case NodeKind::STRING:
        return o << "STRING";
    case NodeKind::OBJECT:
        return o << "OBJECT";
    case NodeKind::ARRAY:
        return o << "ARRAY";
    }
    // Never happens
    return o;
}