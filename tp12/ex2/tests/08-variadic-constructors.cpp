#include "../src/HybridArray.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Instances of HybridArray<..., 1+> can be constructed with a variadic list of arguments acting as their parameters")
{
    auto ctn_1 = HybridArray<int, 3>(1, 2);
    REQUIRE(ctn_1.size() == 2);
    REQUIRE(ctn_1[0] == 1);
    REQUIRE(ctn_1[1] == 2);

    auto ctn_2 = HybridArray<float, 3>(0.5f, 1.2f, 5.3f, 6.2f);
    REQUIRE(ctn_2.size() == 4);
    REQUIRE(ctn_2[0] == 0.5f);
    REQUIRE(ctn_2[1] == 1.2f);
    REQUIRE(ctn_2[2] == 5.3f);
    REQUIRE(ctn_2[3] == 6.2f);
}
