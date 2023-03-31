#include <catch2/catch_test_macros.hpp>
#include <list>

TEST_CASE("a. Example of std::list::splice")
{
    std::list<int> list1 = {0, 1, 2};
    std::list<int> list2 = {4, 5};

    // ref_to_list is a &&-reference and may be obtained thanks to std::move
    std::list<int> &&ref_to_list2 = std::move(list2);

    list1.splice(list1.end(), ref_to_list2); // This is done in constant time

    // list1 is now the concatenation of list1 and list2
    REQUIRE(list1 == std::list<int>{0, 1, 2, 4, 5});

    // list2 is empty
    REQUIRE(list2 == std::list<int>{});
}

TEST_CASE("b. Off course, usually we use std::move directly. ")
{
    std::list<int> list1 = {0, 1, 2};
    std::list<int> list2 = {4, 5};

    list1.splice(list1.end(), std::move(list2));

    REQUIRE(list1 == std::list<int>{0, 1, 2, 4, 5});

    REQUIRE(list2 == std::list<int>{});
}
