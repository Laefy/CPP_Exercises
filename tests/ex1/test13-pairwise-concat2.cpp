#include "../../src/ex1.hpp"

#include <catch2/catch_test_macros.hpp>
#include <list>

/*
Your job is to write (in files ex1.{hpp,cpp}) a function pairwise_concatenate(l1,l2) that
- takes as argument two list of lists l1 and l2, where l2 is an r-value reference
                                                                ^
- **moves** the lists inside l1 to the lists inside l2 using `concatenate`
  the content of l2[i] is moved at the end of l1[i] for each i.
*/

TEST_CASE("a. pairwise_concatenate with an r-value reference")
{
    std::list<std::list<int>> list1 = { { 0, 1, 2 }, { 3, 4 }, { 5, 6 } };
    std::list<std::list<int>> list2 = { { 0, 1, 2 }, { 3, 4 }, { 5, 6 } };

    pairwise_concatenate(list1, std::move(list2));
    //                          ^^^^^^^^^^^^^^^^ r-value reference

    std::list<std::list<int>> target1 = { { 0, 1, 2, 0, 1, 2 }, { 3, 4, 3, 4 }, { 5, 6, 5, 6 } };

    REQUIRE(list1 == target1);
}

TEST_CASE("b. If using an r-value reference, elements were moved.")
{
    std::list<std::list<int>> list1 = { { 0, 1, 2 }, { 3, 4 }, { 5, 6 } };
    std::list<std::list<int>> list2 = { { 0, 1, 2 }, { 3, 4 }, { 5, 6 } };

    // Let us record the address of the ints in the lists
    std::list<std::list<int*>> addresses_before = { {}, {}, {} };
    {
        auto addresses_it = addresses_before.begin();
        for (auto& internal_list : list1)
        {
            for (auto& i : internal_list)
                addresses_it->push_back(&i);
            ++addresses_it;
        }
        addresses_it = addresses_before.begin();
        for (auto& internal_list : list2)
        {
            for (auto& i : internal_list)
                addresses_it->push_back(&i);
            ++addresses_it;
        }
    }

    pairwise_concatenate(list1, std::move(list2));

    // Let us look at the integers addresses after the concatenation
    std::list<std::list<int*>> addresses_after = { {}, {}, {} };
    {
        auto addresses_it = addresses_after.begin();
        for (auto& internal_list : list1)
        {
            for (auto& i : internal_list)
                addresses_it->push_back(&i);
            ++addresses_it;
        }
    }

    // The int are still at the same position in memory.
    REQUIRE(addresses_before == addresses_after);
}

TEST_CASE("c. test12 still passes")
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
