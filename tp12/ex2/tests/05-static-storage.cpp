#include "../src/HybridArray.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Under the static limit, elements are allocated statically and contiguously => iterators are preserved")
{
    auto  ctn   = HybridArray<unsigned, 2000> {};
    auto& elm_1 = ctn.push_back(30u);

    while (ctn.size() < ctn.static_size())
    {
        auto& new_elm               = ctn.push_back(0u);
        auto  distance_first_to_new = std::distance(&elm_1, &new_elm);
        REQUIRE(distance_first_to_new + 1u == ctn.size());
    }

    REQUIRE(elm_1 == 30u);
    elm_1 = 500u;
    REQUIRE(ctn[0] == 500u);
}
