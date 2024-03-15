#include "../src/Base.hpp"
#include "../src/DerivedInt.hpp"
#include "../src/DerivedString.hpp"

#include <catch2/catch_test_macros.hpp>
#include <sstream>

class Derived42 : public DerivedInt
{
public:
    Derived42()
        : DerivedInt { 42 }
    {}
    std::string to_string() const { return "6 x 9"; }
};

class DerivedQuaranteDeux : public DerivedString
{
public:
    DerivedQuaranteDeux()
        : DerivedString { "quarante deux" }
    {}
    std::string to_string() const { return "six fois neuf"; }
};

TEST_CASE(
    "On peut afficher une Base avec <<, et cet opérateur est implémenté en utilisant une fonction virtuelle")
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

    Derived42         e3 {};
    Base&             b3 = e3;
    std::stringstream ss3;
    ss3 << b3;
    REQUIRE(ss3.str() == "6 x 9");

    DerivedQuaranteDeux e4 {};
    Base&               b4 = e4;
    std::stringstream   ss4;
    ss4 << b4;
    REQUIRE(ss4.str() == "six fois neuf");
}
