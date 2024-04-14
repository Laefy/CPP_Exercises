#include "../src/HybridArray.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("The static_size function can be used at compile-time")
{
    if constexpr (HybridArray<int, 3>::static_size() != 3)
    {
        // The condition above should compile.
    }
}
