#include "Random.hpp"

#include <random>

int random_value(int min, int max)
{
    auto generator = std::default_random_engine { std::random_device {}() };
    return std::uniform_int_distribution<int> { min, max }(generator);
}

void random_move(int& x, int& y)
{
    auto generator    = std::default_random_engine { std::random_device {}() };
    auto distribution = std::uniform_int_distribution<int> { 0, 4 };

    switch (distribution(generator))
    {
    case 0:
        // No move
        break;

    case 1:
        // Move left
        --x;
        break;

    case 2:
        // Move right
        ++x;
        break;

    case 3:
        // Move down
        ++y;
        break;

    case 4:
        // Move up
        --y;
        break;

    default:
        break;
    }
}
