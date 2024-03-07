#pragma once

#include "Item.hpp"

class Trap : public Item
{
public:
    Trap(int width, int height)
        : Item { width, height }
    {}

    char get_representation() const override { return 'X'; }
};
