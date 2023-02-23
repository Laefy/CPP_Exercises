#pragma once

#include <memory>
#include <string>

class OptionalString
{
public:
    OptionalString()
        : _present { false }
    {}
    OptionalString(std::string value)
        : _present { true }
        , _value { std::move(value) }
    {}

    operator bool() const { return _present; };

    const std::string& value() { return _value; }

private:
    bool        _present;
    std::string _value {};
};
