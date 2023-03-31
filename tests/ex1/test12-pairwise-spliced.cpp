#include <list>
#include <catch2/catch_test_macros.hpp>

#include "../../src/ex1.hpp"

/*
Your job is to write a function pairwise_splice(l1,l2) that
- takes as argument two list of lists l1 and l2
- **moves** the lists inside l1 to the lists inside l2 using `splice`:
  the content of l2[i] is moved into l1[i] for each i.
*/

TEST_CASE("a. Example of std::list::splice")
{
    std::list<std::list<int>> list1 = {{0, 1, 2},
                                       {3, 4},
                                       {5, 6}};
    std::list<std::list<int>> list2 = {{0, 1, 2},
                                       {3, 4},
                                       {5, 6}};

    pairwise_splice(list1, std::move(list2));

    std::list<std::list<int>> target1 = {{0, 1, 2, 0, 1, 2},
                                         {3, 4, 3, 4},
                                         {5, 6, 5, 6}};

    REQUIRE(list1 == target1);

    std::list<std::list<int>> target2 = {{}, {}, {}};
    REQUIRE(list2 == target2);
}

TEST_CASE("b. The lists were moved and copied.")
{
    std::list<std::list<int>> list1 = {{0, 1, 2},
                                       {3, 4},
                                       {5, 6}};
    std::list<std::list<int>> list2 = {{0, 1, 2},
                                       {3, 4},
                                       {5, 6}};

    // Let us record the address of the ints in the lists
    std::list<std::list<int *>> addresses_before = {{}, {}, {}};
    {
        auto addresses_it = addresses_before.begin();
        for (auto &internal_list : list1)
        {
            for (auto &i : internal_list)
                addresses_it->push_back(&i);
            ++addresses_it;
        }
        addresses_it = addresses_before.begin();
        for (auto &internal_list : list2)
        {
            for (auto &i : internal_list)
                addresses_it->push_back(&i);
            ++addresses_it;
        }
    }

    // We splice
    pairwise_splice(list1, std::move(list2));

    // Let us look at the integers addresses after the splice
    std::list<std::list<int *>> addresses_after = {{}, {}, {}};
    {
        auto addresses_it = addresses_after.begin();
        for (auto &internal_list : list1)
        {
            for (auto &i : internal_list)
                addresses_it->push_back(&i);
            ++addresses_it;
        }
    }

    // The int are still at the same position in memory.
    REQUIRE(addresses_before == addresses_after);
}

TEST_CASE("c. The case where list1.size() > list2.size() is treated")
{
    std::list<std::list<int>> list1 = {{0, 1, 2},
                                       {3, 4},
                                       {5, 6}};
    std::list<std::list<int>> list2 = {{0, 1, 2},
                                       {3, 4}};

    pairwise_splice(list1, std::move(list2));

    std::list<std::list<int>> target1 = {{0, 1, 2, 0, 1, 2},
                                         {3, 4, 3, 4},
                                         {5, 6}};
    REQUIRE(list1 == target1);

    std::list<std::list<int>> target2 = {{}, {}};
    REQUIRE(list2 == target2);
}

TEST_CASE("d. The case where list1.size() < list2.size() is treated")
{
    std::list<std::list<int>> list1 = {{0, 1, 2},
                                       {3, 4}};
    std::list<std::list<int>> list2 = {{0, 1, 2},
                                       {3, 4},
                                       {5, 6}};

    pairwise_splice(list1, std::move(list2));

    std::list<std::list<int>> target1 = {{0, 1, 2, 0, 1, 2},
                                         {3, 4, 3, 4},
                                         {5, 6}};
    REQUIRE(list1 == target1);

    std::list<std::list<int>> target2 = {{}, {}, {}};
    REQUIRE(list2 == target2);
}