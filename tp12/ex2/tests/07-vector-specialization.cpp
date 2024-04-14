#include "../src/HybridArray.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE(
    "If the static size is 0, then the container is specialized so that it can be used directly as a std::vector")
{
    auto                      ctn        = HybridArray<std::string, 0> {};
    std::vector<std::string>& ctn_as_vec = ctn;

    ctn_as_vec.push_back("blop");
    REQUIRE(ctn.front() == "blop");
}
