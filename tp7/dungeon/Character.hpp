#pragma once

#include "Entity.hpp"
#include "Logger.hpp"
#include "Potion.hpp"
#include "Trap.hpp"

#include <iostream>

class Character : public Entity
{
public:
    Character(int x, int y)
        : Entity { x, y }
    {}

    ~Character() override
    {
        logger << "A character died at position (" << get_x() << "," << get_y() << ")" << std::endl;
    }

    char get_representation() const override
    {
        switch (_life)
        {
        case 2:
            return 'O';
        case 1:
            return 'o';
        default:
            return ' ';
        }
    }

    void interact_with(Entity& other) override
    {
        if (auto* trap = dynamic_cast<Trap*>(&other); trap != nullptr && _life > 0u)
        {
            trap->consume();
            --_life;
        }
        else if (auto* potion = dynamic_cast<Potion*>(&other); potion != nullptr && _life == 1u)
        {
            potion->consume();
            ++_life;
        }
    }

    bool should_destroy() const override { return _life == 0u; }

private:
    unsigned int _life = 2u;
};
