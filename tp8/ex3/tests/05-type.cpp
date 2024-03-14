#include "../src/Base.hpp"
#include "../src/DerivedInt.hpp"
#include "../src/DerivedString.hpp"

#include <catch2/catch_test_macros.hpp>

class DerivedEmptyString : public DerivedString
{
public:
    DerivedEmptyString()
        : DerivedString("")
    {}

public:
    std::string type() const { return "This is not my type"; }
    std::string type() { return "This is not my type"; }
};

TEST_CASE("Base possède une fonction-membre type() donnant le type dynamique mais qui n'est pas virtuelle")
{
    const Base* b = nullptr; // Ceci est une astuce pour utiliser le type Base
    if (b != nullptr)        // bien qu'on ne puisse pas l'instancier.
    {
        std::string s = b->type();
    }

    DerivedInt i { 1 };
    Base&      b1 = i;
    REQUIRE(i.type() == "Int");
    REQUIRE(b1.type() == "Int");

    DerivedString s { "quarante deux" };
    Base&         b2 = s;
    REQUIRE(s.type() == "String");
    REQUIRE(b2.type() == "String");

    DerivedEmptyString e {};
    Base&              b3 = s;
    REQUIRE(b3.type() == "String");
}