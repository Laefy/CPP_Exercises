#include "../src/01-rm-elems-alg.hpp"

#include <algorithm>
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Remove all negative elements from a vector with an algorithm function")
{
    auto values = std::vector { 5, -1, 24, -3, -4, 11, 11, -238, 0 };
    auto it     = ANSWER_1(values.begin(), values.end(), ANSWER_2);
    values.ANSWER_3(it, values.end());
}