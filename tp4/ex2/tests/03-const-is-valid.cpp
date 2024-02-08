#include "../src/PhoneNumber.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("PhoneNumber::is_valid peut être appelée sur des instances constantes")
{
    const auto phone_number = PhoneNumber { 1, 64, 12, 66, 73 };
    const auto is_valid     = phone_number.is_valid();
    REQUIRE(true == is_valid);
}
