#include "../../lib/concatenate.hpp"

#include <catch2/catch_test_macros.hpp>
#include <list>

TEST_CASE("a. Example of `concatenate` with an l-value reference")
{
    std::list<int> list1 = { 0, 1, 2 };
    std::list<int> list2 = { 4, 5 };

    //                 This is an l-value reference
    //                 vvvvv
    concatenate(list1, list2);
    // ^ This operation done in linear time in list2

    // list1 is now the concatenation of list1 and list2
    REQUIRE(list1 == std::list<int> { 0, 1, 2, 4, 5 });

    // list2 did not change
    REQUIRE(list2 == std::list<int> { 4, 5 });
}

TEST_CASE("b. Example of `concatenate` with an r-value reference")
{
    std::list<int> list1 = { 0, 1, 2 };
    std::list<int> list2 = { 4, 5 };

    //                 std::move  allows to obtain an r-value reference
    //                 vvvvvvvvv
    concatenate(list1, std::move(list2));
    // ^ This operation done in constant time.

    // list1 is now the concatenation of list1 and list2
    REQUIRE(list1 == std::list<int> { 0, 1, 2, 4, 5 });

    // list2 is empty
    REQUIRE(list2 == std::list<int> {});
}
