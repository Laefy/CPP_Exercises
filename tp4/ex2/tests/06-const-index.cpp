#include "../src/PhoneNumber.hpp"

#include <catch2/catch_test_macros.hpp>
#include <string>

TEST_CASE("L'opérateur d'indice peut être appelé sur des instances constantes")
{
    const auto pn = PhoneNumber { 1, 64, 12, 66, 73 };
    auto       nb = pn[0];
    REQUIRE(1 == nb);
}
