#include "../lib/InstanceCounter.hpp"
#include "../src/StringInstancePair.hpp"

#include <catch2/catch_test_macros.hpp>
#include <string>

TEST_CASE("La copy d'une StringInstancePair provoque la copie de l'InstanceCounter")
{
    {
        StringInstancePair p1 { "Test" };
        const auto&        i1 = p1.get_instance_counter();
        const auto&        s1 = p1.get_str();
        StringInstancePair p2 { p1 };
        const auto&        i2 = p2.get_instance_counter();
        const auto&        s2 = p2.get_str();

        REQUIRE(2 == InstanceCounter::constructions());
        REQUIRE(1 == InstanceCounter::copies());
        REQUIRE(0 == InstanceCounter::deletions());

        REQUIRE(s1 == s2);   // Les chaines dans p1 et p2 sont égales
        REQUIRE(&s1 != &s2); // ....mais stocké dans des endroits différentts

        REQUIRE(&i1 == i2.origin()); // L'instance dans p2 est bien une copie de i1.
        REQUIRE(&i1 != &i2);         // Les InstanceCounter sont stockés dans des endroits différents.
    }

    // Toutes les instances construites ont été détruites.
    REQUIRE(InstanceCounter::constructions() == InstanceCounter::deletions());
}
