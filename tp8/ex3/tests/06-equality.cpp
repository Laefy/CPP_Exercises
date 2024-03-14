#include "../src/Base.hpp"
#include "../src/DerivedInt.hpp"
#include "../src/DerivedString.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("On peut tester l'égalité de Base")
{
    DerivedInt i1 { 42 };
    Base&      b1 = i1;
    DerivedInt i2 { 42 };
    Base&      b2 = i1;
    DerivedInt i3 { 24 };
    Base&      b3 = i3;

    // Deux classes dérivées avec la même valeur sont égales si
    // la valeur encapsulée est la même
    REQUIRE(i1 == i2);
    REQUIRE(i2 == i1);
    REQUIRE(b1 == b2);
    REQUIRE(b2 == b1);
    REQUIRE(!(b1 == b3));
    REQUIRE(!(b3 == b1));
    REQUIRE(!(i1 == i3));
    REQUIRE(!(i3 == i1));

    DerivedString s4 { "quarante deux" };
    Base&         b4 = s4;
    DerivedString s5 { "quarante deux" };
    Base&         b5 = s5;
    DerivedString s6 { "vingt quatre" };
    Base&         b6 = s6;

    REQUIRE(b4 == b5);
    REQUIRE(b5 == b4);
    REQUIRE(!(b1 == b6));
    REQUIRE(!(b6 == b1));

    // Deux objets ne sont jamais égaux s'il leurs types dynamique sont différents.
    // On pourra supposer l'invariant suivant.  Etant donné deux objets o1 et o2 qui sont d'un type dérivant
    // de Base, alors o1 et o2 ont le même type dynamique si et seulement si o1.type() == o2.type().
    REQUIRE(!(i1 == s4));
    REQUIRE(!(s4 == i1));
    REQUIRE(!(b4 == b1));
    REQUIRE(!(b1 == b4));
}