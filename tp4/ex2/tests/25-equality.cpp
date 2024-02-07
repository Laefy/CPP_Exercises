#include "../src/PhoneBookEntry.hpp"
#include "../src/PhoneNumber.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Deux PhoneBookEntry sont égales si elles contiennent le même nom")
{
    auto e1 = PhoneBookEntry { "Marcel", PhoneNumber { 1, 64, 0, 66, 73 } };
    auto e2 = PhoneBookEntry { "Marcel", PhoneNumber { 1, 64, 0, 66, 73 } };
    auto e3 = PhoneBookEntry { "Marcel", PhoneNumber { 4, 3, 22, 73, 16 } };
    auto e4 = PhoneBookEntry { "Jean", PhoneNumber { 1, 64, 0, 66, 73 } };

    bool e1_e2_are_equal = e1 == e2;
    REQUIRE(e1_e2_are_equal == true);

    // e1 et e3 sont égaux: ils n'ont pas le même numéro, mais on bien le même nom
    bool e1_e3_are_equal = e1 == e3;
    REQUIRE(e1_e3_are_equal == true);

    // e1 et e4 sont différents: ils ont le même numéro, mais pas le même nom
    bool e1_e4_are_equal = e1 == e4;
    REQUIRE(e1_e4_are_equal == false);
}
