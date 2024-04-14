#include "../src/05-sum.hpp"

#include <catch2/catch_test_macros.hpp>
#include <vector>

#include ANSWER_1

TEST_CASE("Find the function allowing to combine all the elements of a range.")
{
    auto elements = std::vector { 1, 2, 7, 1, 7, 2 };

    auto sum = ANSWER_2(elements.begin(), elements.end(), ANSWER_3A, ANSWER_3B);
    REQUIRE(sum == 1 + 2 + 7 + 1 + 7 + 2);

    auto product = ANSWER_2(elements.begin(), elements.end(), ANSWER_4A, ANSWER_4B);
    REQUIRE(product == 1 * 2 * 7 * 1 * 7 * 2);
}
