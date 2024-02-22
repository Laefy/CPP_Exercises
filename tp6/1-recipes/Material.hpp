#pragma once

#include <iostream>
#include <string>
#include <utility>

class Material
{
    // Affiche le nom d'un materiau.
    friend std::ostream& operator<<(std::ostream& stream, const Material& material)
    {
        return stream << material.get_name();
    }

public:
    Material(std::string name)
        : _name { std::move(name) }
    {
        std::cout << *this << " was created" << std::endl;
    }

    ~Material() { std::cout << *this << " was destroyed" << std::endl; }

    const std::string& get_name() const { return _name; }

private:
    std::string _name;
};
