#include <list>
#include <vector>
#include <array>
#include <set>
#include <catch2/catch_test_macros.hpp>

#include "../../src/ex3.hpp"

// Your job is to implement this function:
#ifdef OMITTED_BY_THE_COMPILER
template <typename T1, typename T2>
constexpr bool content_of_same_type();
#endif

/*
More precisely, `content_of_same_type<X,Y>` must return `true` if
the type of the objects contained in X and Y are exactly the same.
Hints:
    - The type of an container type X can be accessed through X::value_type
      https://en.cppreference.com/w/cpp/container/vector#Member_types
    - See std::is_same<X,Y> to check whether two types are equal
      https://en.cppreference.com/w/cpp/types/is_same
    - You will probably miss a `typename` or two
*/

TEST_CASE("The function `content_of_same_type` works as expected. ")
{
  REQUIRE(content_of_same_type<std::vector<int>, std::vector<int>>() == true);

  REQUIRE(content_of_same_type<std::set<std::string>, std::vector<std::string>>() == true);

  REQUIRE(content_of_same_type<std::vector<std::string>, std::vector<int>>() == false);
}
