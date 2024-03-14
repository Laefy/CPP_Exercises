#include "../lib/InstanceCounter.hpp"
#include "../src/StringInstancePair.hpp"

#include <catch2/catch_test_macros.hpp>
#include <string>

TEST_CASE("Après un move d'une StringInstancePair, l'InstanceCounter contenue reste au même endroit dans la "
          "mémoire.")
{
    StringInstancePair p1 { "Test" };
    const auto&        i1 = p1.get_instance_counter();

    StringInstancePair p2 = std::move(p1);
    const auto&        i2 = p2.get_instance_counter();

    REQUIRE(&i1 == &i2); // Les InstanceCounter référencés par i1 et i2 sont stockées au même endroit.
    REQUIRE(p1.get_str() == "");
    REQUIRE(p2.get_str() == "Test");
}
