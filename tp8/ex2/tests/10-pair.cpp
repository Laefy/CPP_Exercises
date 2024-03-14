#include "../lib/InstanceCounter.hpp"
#include "../src/StringInstancePair.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Il existe une classe StringInstancePair avec deux getters")
{
    StringInstancePair p { "Test" };

    REQUIRE(1 == InstanceCounter::constructions());
    REQUIRE(0 == InstanceCounter::deletions());

    REQUIRE(p.get_str() == "Test");
    InstanceCounter i = p.get_instance_counter();
}
