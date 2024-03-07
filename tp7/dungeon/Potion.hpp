#pragma once

#include "Item.hpp"

class Potion : public Item
{
public:
    Potion(int width, int height)
        : Item { width, height }
    {}

    char get_representation() const override { return '$'; }
};
