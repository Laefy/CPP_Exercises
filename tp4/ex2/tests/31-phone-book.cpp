#include "../src/PhoneBook.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Il existe une classe PhoneBook constructible par défaut")
{
    auto phone_book = PhoneBook {};
}
