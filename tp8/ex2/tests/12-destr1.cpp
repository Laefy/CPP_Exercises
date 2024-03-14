#include "../lib/InstanceCounter.hpp"
#include "../src/StringInstancePair.hpp"

#include <catch2/catch_test_macros.hpp>
#include <string>

TEST_CASE("La destruction d'une StringInstancePair provoque la destruction de l'InstanceCounter")
{
    {
        StringInstancePair p { "Test" };

        REQUIRE(p.get_str() == "Test");
        const auto& i = p.get_instance_counter();

        REQUIRE(0 == InstanceCounter::deletions());
    }

    REQUIRE(1 == InstanceCounter::deletions());
}
