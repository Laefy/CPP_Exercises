#pragma once

#include "Consumable.hpp"

#include <vector>

// A cupboard allows to store consumables.
struct Cupboard
{
    std::vector<Consumable> consumables;
};