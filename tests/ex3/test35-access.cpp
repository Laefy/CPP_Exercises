#include "../../src/ex3.hpp"

#include <array>
#include <catch2/catch_test_macros.hpp>
#include <list>
#include <set>
#include <vector>

// Your job is to write a template function with the signature given below
#ifdef OMITTED_BY_THE_COMPILER
template <typename T>
int access(T const& container, unsigned i);
#endif
// `container` will be assumed to contain int's

/// Even though the tests below cannot verify it, the purpose of the exercice is
// that the function
// - `access<std::vector<int>>(container, i)` calls container[i]
// - `access<std::array<10, int>>(container, i)` calls container[i]
// - `access<std::list<int>>(container, i)` iterates i times because
//    it cannot access the i-th element directly
// - `access<std::set<int>>(container, i)` iterates i times because
//    it cannot access the i-th element directly
//
// Indeed std::vector<int> and std::array<10, int> can be used with [..]
// because they are random access, something you can test with
// your template function `has_random_access`.

TEST_CASE("a. Vector")
{
    std::vector<int> my_vector { 0, 1, 10, 11, 100, 101, 110, 111, 1000 };
    REQUIRE(access<std::vector<int>>(my_vector, 2) == 10);
}

TEST_CASE("b. List")
{
    std::list<int> my_list { 0, 1, 10, 11, 100, 101, 110, 111, 1000 };
    REQUIRE(access /*<std::list<int>>*/ (my_list, 3) == 11);
    //            ^^^^^^^^^^^^^^^^^^^^ can be infered by the compiler
}

TEST_CASE("c. Array")
{
    std::array<int, 9> my_array { 0, 1, 10, 11, 100, 101, 110, 111, 1000 };
    REQUIRE(access(my_array, 5) == 101);
}

TEST_CASE("d. Set")
{
    std::set<int> my_set { 0, 1, 10, 11, 100, 101, 110, 111, 1000 };
    REQUIRE(access(my_set, 4) == 100);
}
