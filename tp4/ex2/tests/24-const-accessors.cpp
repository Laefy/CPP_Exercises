#include "../src/PhoneBookEntry.hpp"
#include "../src/PhoneNumber.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Les accesseurs peuvent être appelées sur des instances constantes")
{
    const auto entry = PhoneBookEntry { "Marcel", PhoneNumber { 1, 64, 0, 66, 73 } };

    std::string name = entry.get_name();
    REQUIRE("Marcel" == name);

    PhoneNumber number = entry.get_number();
    REQUIRE(number.is_valid());
}
