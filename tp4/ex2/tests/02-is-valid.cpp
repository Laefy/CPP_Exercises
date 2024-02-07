#include "../src/PhoneNumber.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE(
    "La fonction-membre is_valid() permet de savoir si les numéros sont bien tous compris entre 0 et 99")
{
    auto       pn1          = PhoneNumber { 1, 64, 0, 66, 73 };
    const auto pn1_is_valid = pn1.is_valid();
    REQUIRE(true == pn1_is_valid);

    auto       pn2          = PhoneNumber { 1, 103, 12, 66, 73 };
    const auto pn2_is_valid = pn2.is_valid();
    REQUIRE(false == pn2.is_valid());

    auto       pn3          = PhoneNumber { -1, 64, 12, 66, 73 };
    const auto pn3_is_valid = pn3.is_valid();
    REQUIRE(false == pn3.is_valid());
}
