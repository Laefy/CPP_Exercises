#include "../src/Base.hpp"
#include "../src/DerivedInt.hpp"
#include "../src/DerivedString.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Les deux classes DerivedInt et DerivedString héritent de Base et implémentent la fonction-membre "
          "is_null()")
{
    DerivedInt i1 { 42 };
    Base&      b1 = i1;
    REQUIRE(i1.is_null() == false);
    REQUIRE(b1.is_null() == false);

    DerivedInt i2 { 0 };
    Base&      b2 = i2;
    REQUIRE(i2.is_null() == true); // Pour DerivedInt; is_null est un test à 0
    REQUIRE(b2.is_null() == true);

    DerivedString s3 { "quarante deux" };
    Base&         b3 = s3;
    REQUIRE(s3.is_null() == false);
    REQUIRE(b3.is_null() == false);

    DerivedString s4 { "" };
    Base&         b4 = s4;
    REQUIRE(s4.is_null() == true); // Pour DerivedString; is_null est un test à ""
    REQUIRE(b4.is_null() == true);
}
