#include "../src/HybridArray.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("A size function returns the number of elements in the container")
{
    auto ctn = HybridArray<std::string, 3> {};
    REQUIRE(ctn.size() == 0);

    ctn.push_back("pouet");
    REQUIRE(ctn.size() == 1);

    ctn.push_back("toto");
    REQUIRE(ctn.size() == 2);
}
