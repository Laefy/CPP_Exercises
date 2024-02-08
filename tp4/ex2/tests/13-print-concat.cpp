#include "../src/PhoneNumber.hpp"

#include <catch2/catch_test_macros.hpp>
#include <sstream>

TEST_CASE("L'appel à l'opérateur << est concaténable")
{
    auto pn = PhoneNumber { 1, 64, 0, 66, 73 };

    std::stringstream stream;
    stream << "Phone number is: " << pn << ".";

    REQUIRE(stream.str() == "Phone number is: 0164006673.");
}
