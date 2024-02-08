#include "../src/PhoneNumber.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Il existe une classe PhoneNumber dont le constructeur attend 5 entiers positifs")
{
    auto phone_number = PhoneNumber { 1, 64, 12, 66, 73 };
}
