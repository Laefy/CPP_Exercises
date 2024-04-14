#include "../src/HybridArray.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("An index operator is available for the container")
{
    auto ctn_int = HybridArray<int, 3> {};
    auto ctn_str = HybridArray<std::string, 3> {};

    auto& elm_1 = ctn_int.push_back(1);
    REQUIRE(&ctn_int[0] == &elm_1);

    ctn_int.push_back(2);
    ctn_int.push_back(3);
    REQUIRE(ctn_int[2] == 3);

    ctn_str.push_back("pouet");
    REQUIRE(ctn_str[0] == "pouet");

    ctn_str.push_back("toto");
    ctn_str[1] = "blab";
    REQUIRE(ctn_str[1] == "blab");
}
