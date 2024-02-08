#include "../src/PhoneNumber.hpp"

#include <catch2/catch_test_macros.hpp>
#include <string>

TEST_CASE("PhoneNumber a un opérateur d'indice pour accéder à chaque numéro")
{
    auto pn = PhoneNumber { 1, 64, 12, 66, 73 };

    auto n0 = pn[0];
    REQUIRE(1 == n0);

    auto n1 = pn[1];
    REQUIRE(64 == n1);

    auto n2 = pn[2];
    REQUIRE(12 == n2);

    auto n3 = pn[3];
    REQUIRE(66 == n3);

    auto n4 = pn[4];
    REQUIRE(73 == n4);
}
