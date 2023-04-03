#include "../../src/ex3.hpp"

#include <array>
#include <catch2/catch_test_macros.hpp>
#include <list>
#include <set>
#include <vector>

// Using `if constexpr` and `contain_same_thing` write a function
#ifdef OMITTED_BY_THE_COMPILER
template <typename T1, typename T2>
void add_all(T1& t1, const T2& t2);
#endif
// that copies all elements from t2 in t1 if they contain things
// of the same type or does nothing otherwise.

TEST_CASE("a. Adding a list to a vector")
{
    std::vector<int> my_vector { 0 };
    std::list<int>   my_list { 1 };
    add_all<std::vector<int>, std::list<int>>(my_vector, my_list);
    REQUIRE(my_vector == std::vector<int> { 0, 1 });
}

TEST_CASE("b. The compiler can infer the template typenames so we can omit them. How?")
{
    std::vector<int> my_vector { 0 };
    std::list<int>   my_list { 1 };
    add_all /* <std::vector<int>, std::list<int>> */ (my_vector, my_list);
    //      ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ infered by the compiler
    REQUIRE(my_vector == std::vector<int> { 0, 1 });
}

TEST_CASE("c. Adding a list to a vector of with wrong content does nothing")
{
    std::vector<int>       my_vector { 0 };
    std::list<std::string> my_list { "1" };
    add_all(my_vector, my_list);
    REQUIRE(my_vector == std::vector<int> { 0 });
}

TEST_CASE("d. Adding a vector to a list")
{
    std::list<int>   my_list { 1 };
    std::vector<int> my_vector { 0 };
    add_all(my_list, my_vector);
    REQUIRE(my_list == std::list<int> { 1, 0 });
}

TEST_CASE("e. Adding an array to a list")
{
    std::array<int, 3> my_array { 0, -1, -2 };
    std::list<int>     my_list { 1 };
    add_all(my_list, my_array);
    REQUIRE(my_list == std::list<int> { 1, 0, -1, -2 });
}

// Question: this test would not compile.  Why?
TEST_CASE("f. Adding a list to an array: This code would not compile. Why?")
{
#ifdef OMITTED_BY_COMPILER
    std::array<int, 2> my_array { 0 };
    std::list<int>     my_list { 1 };
    add_all(my_list, my_vector);
    REQUIRE(my_array == std::array<int, 2> { 0, 1 });
#endif
}