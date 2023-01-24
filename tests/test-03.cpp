#include <Plush.hpp>

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Test 03 - "
          "La fonction get_cost ne modifie pas les attributs de Plush.")
{
    const auto plush = Plush {};
    REQUIRE(plush.get_cost() == 10);
}
