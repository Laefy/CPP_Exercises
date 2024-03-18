#include "Base.hpp"

#include <sstream>

class DerivedInt : public Base
{
public:
    DerivedInt(int d)
        : Base("Int")
        , _data { d }
    {}

    int         data() { return _data; }
    bool        is_null() const override { return _data == 0; }
    std::string to_string() const override
    {
        std::stringstream ss;
        ss << _data;
        return ss.str();
    }

protected:
    virtual bool is_equal_assuming_same_type(const Base& b) const override
    {
        return (dynamic_cast<const DerivedInt&>(b)._data == _data);
    }

private:
    int _data;
};