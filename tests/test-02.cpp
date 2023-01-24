#include <Plush.hpp>

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Test 02 - "
          "Par defaut, une peluche coute 10 euros.")
{
    auto plush = Plush {};
    REQUIRE(plush.get_cost() == 10);
}
