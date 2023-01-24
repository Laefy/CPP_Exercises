#include <Plush.hpp>

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Test 05 - "
          "On peut instancier une peluche avec son cout.")
{
    auto plush = Plush { 35 };
    REQUIRE(plush.get_cost() == 35);
}
