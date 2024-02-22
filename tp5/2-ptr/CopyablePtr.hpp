#pragma once

#include "Object.hpp"

#include <utility>

class CopyablePtr
{
public:
    CopyablePtr() = default;

    CopyablePtr(int value)
        : _obj { new Object { value } }
    {}

    CopyablePtr(const CopyablePtr& other)
        : _obj { other == nullptr ? nullptr : new Object { *other } }
    {}

    CopyablePtr(CopyablePtr&& other) { std::swap(_obj, other._obj); }

    ~CopyablePtr() { delete _obj; }

    bool operator==(std::nullptr_t) const { return _obj == nullptr; }

    Object& operator*() const { return *_obj; }

    CopyablePtr& operator=(std::nullptr_t)
    {
        delete _obj;
        _obj = nullptr;

        return *this;
    }

    // CopyablePtr& operator=(const CopyablePtr& other)
    // {
    //     if (this != &other)
    //     {
    //         delete _obj;
    //         _obj = other == nullptr ? nullptr : new Object { *other };
    //     }
    //     return *this;
    // }

    // CopyablePtr& operator=(CopyablePtr&& other)
    // {
    //     if (this != &other)
    //     {
    //         *this = nullptr;
    //         std::swap(_obj, other._obj);
    //     }
    //     return *this;
    // }

    // Bonus F
    CopyablePtr& operator=(CopyablePtr other)
    {
        std::swap(_obj, other._obj);
        return *this;
    }

private:
    Object* _obj = nullptr;
};