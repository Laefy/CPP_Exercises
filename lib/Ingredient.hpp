#pragma once

#include "Unit.hpp"

#include <functional>
#include <string>

// An ingredient is a type of consumable.
struct Ingredient
{
    // The name of the ingredient.
    std::string name;

    // The unit associated to it.
    std::reference_wrapper<const Unit> unit;

    bool operator==(const Ingredient& other) const { return name == other.name; }
    bool operator<(const Ingredient& other) const { return name < other.name; }
};
