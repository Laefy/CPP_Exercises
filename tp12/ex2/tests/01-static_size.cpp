#include "../src/HybridArray.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("A static_size function allows to retrive the size of the container")
{
    auto s1 = HybridArray<int, 1>::static_size();
    REQUIRE(s1 == 1);

    auto s8 = HybridArray<int, 8>::static_size();
    REQUIRE(s8 == 8);
}
