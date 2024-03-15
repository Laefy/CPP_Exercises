#include "../src/Base.hpp"
#include "../src/DerivedInt.hpp"
#include "../src/DerivedString.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Il existent deux classes DerivedInt et DerivedString qui encapsulent un entier et une chaîne, "
          "respectivement")
{
    DerivedInt i1 { 42 };
    REQUIRE(i1.data() == 42);

    DerivedString s2 { "quarante deux" };
    REQUIRE(s2.data() == "quarante deux");
}
