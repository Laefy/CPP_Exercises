#include "../src/00-rm-elems-for.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Remove all negative elements from a vector with a for-loop")
{
    auto values = std::vector { 5, -1, 24, -3, -4, 11, 11, -238, 0 };

    for (auto it = ANSWER_1; it != ANSWER_2; ANSWER_3)
    {
        const auto is_negative = (ANSWER_4);
        if (is_negative)
        {
            ANSWER_5;
        }
        else
        {
            ANSWER_6;
        }
    }

    REQUIRE(values == std::vector { 5, 24, 11, 11, 0 });
}