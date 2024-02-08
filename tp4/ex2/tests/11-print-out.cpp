#include "../src/PhoneNumber.hpp"

#include <catch2/catch_test_macros.hpp>
#include <iostream>

TEST_CASE("La classe PhoneNumber dispose d'un opérateur de flux de sortie")
{
    auto pn = PhoneNumber { 1, 64, 0, 66, 73 };
    std::cout << pn;
}
