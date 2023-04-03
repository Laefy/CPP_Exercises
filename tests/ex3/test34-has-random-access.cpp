#include "../../src/ex3.hpp"

#include <array>
#include <catch2/catch_test_macros.hpp>
#include <list>
#include <set>
#include <vector>

// Your job is to write a template function with the signature given below
#ifdef OMITTED_BY_THE_COMPILER
template <typename T>
constexpr bool has_random_access();
#endif
// It must return `true` if and only if T is a container which
// features *random access*. It means that the i-th element
// may be accessed in constant time
// - std::vector<..> and std::array<..> are random access
// - std::list<..> and set<..> are NOT.

// C++ has a mechanism for container to declare whether they
// are random access: the iterator category must be
// `std::random_access_iterator_tag`
// - The type of the iterator of a container T is given by
//   T::iterator
// - If X is an iterator type, its category can be accessed
//   throught std::iterator_traits<X>::iterator_category

TEST_CASE("a. Vector is random access")
{
    REQUIRE(has_random_access<std::vector<int>>() == true);
}

TEST_CASE("b. List is NOT random access")
{
    REQUIRE(has_random_access<std::list<int>>() == false);
}

TEST_CASE("c. Array is random access")
{
    REQUIRE(has_random_access<std::array<int, 9>>() == true);
}

TEST_CASE("d. Set is NOT random access")
{
    REQUIRE(has_random_access<std::set<int>>() == false);
}