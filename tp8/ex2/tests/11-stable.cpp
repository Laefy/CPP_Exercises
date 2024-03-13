#include "../lib/InstanceCounter.hpp"
#include "../src/StringInstancePair.hpp"

#include <catch2/catch_test_macros.hpp>
#include <string>

TEST_CASE("L'instance contenue dans une StringInstancePair est stable par move")
{
    StringInstancePair p1 { "Test" };
    const auto&        i1 = p1.ins();

    StringInstancePair p2 = std::move(p1);
    const auto&        i2 = p2.ins();

    REQUIRE(&i1 == &i2); // Les InstanceCounter référencés par i1 et i2 sont stockées au même endroit.
    REQUIRE(p1.str() == "");
    REQUIRE(p2.str() == "Test");
}
