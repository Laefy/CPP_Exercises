#pragma once

#include <iostream>

class Object
{
public:
    Object(int value)
        : _value { value }
    {
        std::cout << *this << " has been created" << std::endl;
    }

    Object(const Object& other)
        : _value { other._value }
        , _empty { other._empty }
    {
        std::cout << other << " has been copied into " << *this << std::endl;
    }

    Object(Object&& other)
        : _value { other._value }
        , _empty { other._empty }
    {
        other._empty = true;
        std::cout << other << " has been moved into " << *this << std::endl;
    }

    ~Object() { std::cout << *this << " has been destroyed" << std::endl; }

    friend std::ostream& operator<<(std::ostream& stream, const Object& obj)
    {
        if (obj._empty)
        {
            return stream << "Object #" << obj._id << " [[ empty ]]";
        }
        else
        {
            return stream << "Object #" << obj._id << " [[ " << obj._value << " ]]";
        }
    }

private:
    inline static size_t _next_id = 0;

    size_t _id    = _next_id++;
    int    _value = 0;
    bool   _empty = false;
};
