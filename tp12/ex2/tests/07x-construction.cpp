#include "../src/HybridArray.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("The std::vector constructors are inherited by the specialization")
{
    auto ctn_1 = HybridArray<char, 0>(3, 'A'); // 3 times A
    REQUIRE(ctn_1.size() == 3);
    REQUIRE(ctn_1[1] == 'A');

    auto ctn_2 = HybridArray<double, 0> { 2.0, 5.2 }; // initializer_list
    REQUIRE(ctn_2.size() == 2);
    REQUIRE(ctn_2[0] == 2.0);
    REQUIRE(ctn_2[1] == 5.2);

    auto ctn_3 = HybridArray<char, 0>(ctn_1.begin(), ctn_1.end()); // iterators
    REQUIRE(ctn_3.size() == 3);
    REQUIRE(ctn_3[0] == 'A');
    REQUIRE(ctn_3[1] == 'A');
    REQUIRE(ctn_3[2] == 'A');
}
