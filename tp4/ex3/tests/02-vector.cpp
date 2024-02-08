#include "../src/02-vector.hpp"

#include <catch2/catch_test_macros.hpp>
#include <sstream>
#include <vector>

TEST_CASE("Utilisation de std::vector")
{
    auto values = std::vector<int> { 1, 3, 4, 5 };

    auto nb_elements = values.ANSWER_1();
    REQUIRE(4 == nb_elements);

    std::stringstream stream;
    ANSWER_2A(auto value ANSWER_2B values)
    {
        stream << value;
    }
    REQUIRE("1345" == stream.str());

    auto last_value = values.ANSWER_3();
    REQUIRE(5 == last_value);

    auto new_value = 2;
    values.ANSWER_4(new_value);
    REQUIRE(values == std::vector<int> { 1, 3, 4, 5, 2 });

    values.ANSWER_5();
    REQUIRE(values == std::vector<int> {});
}
