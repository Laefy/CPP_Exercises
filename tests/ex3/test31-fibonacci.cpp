#include <catch2/catch_test_macros.hpp>
#include <array>

#include "../../src/ex3.hpp"

// Here is an example of a naive implementation of the Fibonacci sequence.
unsigned fibonacci_runtime(unsigned i)
{
  if (i < 2)
    return 1;
  else
    return fibonacci_runtime(i - 1) + fibonacci_runtime(i - 2);
}
// Here are the first terms of the Fibonacci sequence:
// F0  F1  F2  F3  F4  F5  F6  F7  F8  F9  ...
// 1 	 1 	 2 	 3 	 5   8   13  21  34  55  ...

// Your job is to implement in a template function  `fibonacci<1>()` that may be
// used at compile-time.

// Question: explain why you need `if constexpr`.

TEST_CASE("The function `content_of_same_type` works as expected. ")
{
  std::array<int, fibonacci<1>()> a1;
  //              ^^^^^^^^^^^^^^  the size of the array a1 is the 1st Fibonacci number,
  REQUIRE(a1.size() == 1); //     that is, 1

  std::array<int, fibonacci<3>()> a3;
  //              ^^^^^^^^^^^^^^  the size of the array a3 is the 3rd Fibonacci number,
  REQUIRE(a3.size() == 3); //     that is, 3

  std::array<int, fibonacci<9>()> a9;
  //              ^^^^^^^^^^^^^^  the size of the array a9 is the 9th Fibonacci number,
  REQUIRE(a9.size() == 55); //    that is, 55
}
