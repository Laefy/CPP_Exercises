#include "../src/06-templates.hpp"

#include <catch2/catch_test_macros.hpp>
#include <string>

template ANSWER_1 bool check_occurences_count(const std::string& s)
{
    size_t count = 0;

    for (auto c : s)
    {
        if (c == TParam_1)
        {
            ++count;
        }
    }

    return count == TParam_2;
}

template ANSWER_2 std::string concat(TParam_1&& v1, const TParam_2& v2)
{
    return std::string { std::forward<TParam_1>(v1) } + v2;
}

TEST_CASE("Find the correct signature for the template.")
{
    REQUIRE(check_occurences_count<'h', 3>("hello") == false);
    REQUIRE(check_occurences_count<'l', 2>("hello") == true);

    REQUIRE(concat("hello", " Gontrand") == "hello Gontrand");
    REQUIRE(concat(std::string { "I " }, "love dogs") == "I love dogs");
}
