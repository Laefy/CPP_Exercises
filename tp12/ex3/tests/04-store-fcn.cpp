#include "../src/04-store-fcn.hpp"

#include <catch2/catch_test_macros.hpp>
#include <string>

#include ANSWER_00

template <typename T>
using Predicate = ANSWER_10<ANSWER_11(const T&)>;

template <typename T>
using Consumer = ANSWER_10<void(ANSWER_12)>;

template <typename T>
using Producer = ANSWER_10<ANSWER_13(ANSWER_14)>;

TEST_CASE("Find the right type for the aliases, and complete the code below")
{
    int            value               = 5;
    Predicate<int> is_lower_than_value = ANSWER_20;
    REQUIRE(is_lower_than_value(5) == false);
    REQUIRE(is_lower_than_value(4) == true);
    value = 10;
    REQUIRE(is_lower_than_value(5) == true);
    REQUIRE(is_lower_than_value(11) == false);

    std::string word_1 = "hello";
    std::string word_2 = "PoUeT pOuEt";
    Consumer<std::string> repeat = ANSWER_21;
    repeat(word_1);
    REQUIRE(word_1 == "hello hello");
    repeat(word_2);
    REQUIRE(word_2 == "PoUeT pOuEt PoUeT pOuEt");

    Producer<unsigned int> next_unsigned = ANSWER_22;
    REQUIRE(next_unsigned() == 0u);
    REQUIRE(next_unsigned() == 1u);
    REQUIRE(next_unsigned() == 2u);
    REQUIRE(next_unsigned() == 3u);
}
