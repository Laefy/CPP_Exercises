#pragma once

#include <string>

class DerivedString;
class DerivedInt;

class Base
{
public:
    Base()
        : Base("None")
    {}

    Base(std::string type)
        : _type { type }
    {}

    std::string const&  type() const { return _type; }
    virtual bool        is_null() const   = 0;
    virtual std::string to_string() const = 0;

    bool operator==(const Base& other) const
    {
        if (other.type() != this->type())
            return false;
        return (is_equal_assuming_same_type(other));
    }

protected:
    virtual bool is_equal_assuming_same_type(const Base& b) const = 0;

private:
    std::string _type;
};

inline std::ostream& operator<<(std::ostream& o, const Base& b)
{
    return o << b.to_string();
}