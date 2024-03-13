#include "../src/Base.hpp"
#include "../src/DerivedInt.hpp"
#include "../src/DerivedString.hpp"

#include <catch2/catch_test_macros.hpp>
#include <iostream>

TEST_CASE("On peut afficher une Base avec l'opérateur <<")
{
    DerivedInt        i1 { 42 };
    Base&             b1 = i1;
    std::stringstream ss1;
    ss1 << b1;
    REQUIRE(ss1.str() == "42");

    DerivedString     s2 { "quarante deux" };
    Base&             b2 = s2;
    std::stringstream ss2;
    ss2 << b2;
    REQUIRE(ss2.str() == "quarante deux");
}
