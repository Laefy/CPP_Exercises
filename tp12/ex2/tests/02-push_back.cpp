#include "../src/HybridArray.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("A push_back function allows to add an element in the container")
{
    auto ctn_int = HybridArray<int, 3> {};
    ctn_int.push_back(1);
    ctn_int.push_back(2);
    ctn_int.push_back(3);

    auto ctn_str = HybridArray<std::string, 3> {};
    ctn_str.push_back("pouet");
    ctn_str.push_back("toto");

    auto& elm_3 = ctn_str.push_back("truc");
    REQUIRE(elm_3 == "truc");
}
