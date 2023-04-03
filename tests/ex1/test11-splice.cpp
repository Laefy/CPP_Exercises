#include <catch2/catch_test_macros.hpp>
#include <list>

TEST_CASE("Example of std::list::splice")
{
    std::list<int> list1 = { 0, 1, 2 };
    std::list<int> list2 = { 4, 5 };

    //                        std::move  allows to obtain an r-value reference
    //                        vvvvvvvvvvvvvvvv
    list1.splice(list1.end(), std::move(list2));
    //    ^^^^^^ This operation done in constant time

    // list1 is now the concatenation of list1 and list2
    REQUIRE(list1 == std::list<int> { 0, 1, 2, 4, 5 });

    // list2 is empty
    REQUIRE(list2 == std::list<int> {});
}
