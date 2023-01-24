#include <Plush.hpp>

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Test 04 - "
          "On peut modifier le cout d'une peluche.")
{
    auto plush = Plush {};
    plush.set_cost(15);
    REQUIRE(plush.get_cost() == 15);
}
