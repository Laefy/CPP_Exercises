#pragma once

#include "Ingredient.hpp"

#include <map>
#include <string>

// A recipe lists the ingredients and the quantities required to prepare it.
struct Recipe
{
    // The name of the recipe.
    std::string name;

    // The quantity required for each ingredient.
    std::map<const Ingredient*, float> quantity_by_ingredient;
};
