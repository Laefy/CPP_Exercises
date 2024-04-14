#include "../src/HybridArray.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Above the static limit, elements are moved to the dynamic storage")
{
    auto  ctn   = HybridArray<unsigned, 2> {};

    auto& elm_1 = ctn.push_back(30u);
    auto& elm_2 = ctn.push_back(60u);
    REQUIRE(&elm_1 == &ctn[0]);
    REQUIRE(&elm_2 == &ctn[1]);

    // Now exceeding the static limit...
    auto& elm_3 = ctn.push_back(90u);

    // Previous iterators are invalidated, as objects are moved from the static storage to the dynamic one 
    REQUIRE(&elm_1 != &ctn[0]);
    REQUIRE(&elm_2 != &ctn[1]);

    // Elements are still correctly accessible through []
    REQUIRE(ctn[0] == 30u);
    REQUIRE(ctn[1] == 60u);
    REQUIRE(ctn[2] == 90u);

    // Elements are still contiguous in memory
    REQUIRE(std::distance(&ctn[0], &ctn[1]) == 1); 
    REQUIRE(std::distance(&ctn[1], &ctn[2]) == 1); 
    REQUIRE(std::distance(&ctn[2], &ctn[3]) == 1); 

    // The size function returns the correct value
    REQUIRE(ctn.size() == 3);

    for (auto i = 0u; i < 100u; ++i)
    {
        ctn.push_back(i);
    }

    REQUIRE(ctn.size() == 103);
}
