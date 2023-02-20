#include "StringLeaf.hpp"

std::string StringLeaf::print() const
{
    std::string result;
    result.reserve(_data.size() + 2);
    result += '"';
    for (char c : _data)
    {
        if (c == '\\' || c == '"')
            result += '\\';
        result += c;
    }
    result += '"';
    return result;
}

bool StringLeaf::operator==(const Node& other) const
{
    if (other.kind() != kind())
        return false;
    return (_data == other.as_StringLeaf()->_data);
}

std::unique_ptr<StringLeaf> StringLeaf::make_ptr(std::string s)
{
    return std::make_unique<StringLeaf>(std::move(s));
}