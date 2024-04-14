#include "../src/HybridArray.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("The size function can be used on constant instances")
{
    auto        ctn       = HybridArray<std::string, 3> {};
    const auto& const_ctn = ctn;

    REQUIRE(const_ctn.size() == 0);

    ctn.push_back("pouet");
    REQUIRE(const_ctn.size() == 1);

    ctn.push_back("toto");
    REQUIRE(const_ctn.size() == 2);
}
