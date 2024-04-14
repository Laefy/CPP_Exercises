#include "../src/03-which-container.hpp"

#include <catch2/catch_test_macros.hpp>
#include <sstream>

#include ANSWER_1

TEST_CASE("Find the correct container.")
{
    auto dictionary = ANSWER_2 { { "two", 2 }, { "six", 6 } };

    // Contraint: complexity of the access is O(log(n))
    REQUIRE(dictionary["two"] == 2);
    REQUIRE(dictionary["six"] == 6);

    // Constraint: complexity of the insertion is O(log(n))
    dictionary.ANSWER_3("ten", 10);
    dictionary.ANSWER_3("ten_again", 10);
    REQUIRE(dictionary["ten"] == 10);
    REQUIRE(dictionary["ten_again"] == 10);

    dictionary.ANSWER_4("sixteen", 16);
    dictionary.ANSWER_4("one", 1);
    REQUIRE(dictionary["sixteen"] == 16);
    REQUIRE(dictionary["one"] == 1);

    auto str = std::stringstream {};
    for (auto ANSWER_5 : dictionary)
    {
        str << key << ": " << value << "\n";
    }
    REQUIRE(str.str().empty() == false);
}
