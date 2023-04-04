#include "../../src/ex1.hpp"

#include <catch2/catch_test_macros.hpp>
#include <list>

/*
Your job is to write (in files ex1.{hpp,cpp}) a function pairwise_concatenate(l1,l2) that
- takes as argument two list of lists l1 and l2, where l2 is a l-value reference
                                                               ^
- **copies** the lists inside l1 to the lists inside l2 using `concatenate`
  the content of l2[i] is moved into l1[i] for each i.
*/

TEST_CASE("a. Pairwise_concatenate with an l-value reference")
{
    std::list<std::list<int>> list1 = { { 0, 1, 2 }, { 3, 4 }, { 5, 6 } };
    std::list<std::list<int>> list2 = { { 0, 1, 2 }, { 3, 4 }, { 5, 6 } };

    pairwise_concatenate(list1, list2);
    //                          ^^^^^ l-value reference

    std::list<std::list<int>> target1 = { { 0, 1, 2, 0, 1, 2 }, { 3, 4, 3, 4 }, { 5, 6, 5, 6 } };
    REQUIRE(list1 == target1);

    std::list<std::list<int>> target2 = { { 0, 1, 2 }, { 3, 4 }, { 5, 6 } };
    REQUIRE(list2 == target2);
}
