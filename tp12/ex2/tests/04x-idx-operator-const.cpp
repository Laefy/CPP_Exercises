#include "../src/HybridArray.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("The index operator can be used on constant instances")
{
    auto        ctn       = HybridArray<int, 3> {};
    const auto& ctn_const = ctn;
    ctn.push_back(1);
    ctn.push_back(2);
    ctn.push_back(3);

    REQUIRE(ctn_const[0] == 1);
    REQUIRE(ctn_const[1] == 2);
    REQUIRE(ctn_const[2] == 3);
}
