#include "../src/PhoneBookEntry.hpp"
#include "../src/PhoneNumber.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("L'opérateur d'égalité peut être appelé sur des instances constantes")
{
    const auto e1 = PhoneBookEntry { "Marcel", PhoneNumber { 1, 64, 0, 66, 73 } };
    const auto e2 = PhoneBookEntry { "Jean", PhoneNumber { 1, 64, 0, 66, 73 } };

    const auto are_equal = e1 == e2;
    REQUIRE(false == are_equal);
}
