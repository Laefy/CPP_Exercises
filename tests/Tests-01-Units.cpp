#include "../lib/Unit.hpp"
#include "../src/Kitchen.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Units can be registered in the Kitchen")
{
    auto kitchen = Kitchen {};

    const auto& piece_unit = kitchen.register_unit(Unit { "" });
    REQUIRE(piece_unit.name == "");

    const auto& ml_unit = kitchen.register_unit(Unit { "ml" });
    REQUIRE(ml_unit.name == "ml");

    const auto& g_unit = kitchen.register_unit(Unit { "g" });
    REQUIRE(g_unit.name == "g");
}

TEST_CASE("Units can be retrieved from the Kitchen with their name")
{
    auto kitchen = Kitchen {};

    SECTION("If not registered, it returns null")
    {
        const auto* searched_unit = kitchen.find_unit("l");
        REQUIRE(searched_unit == nullptr);
    }

    const auto& l_unit = kitchen.register_unit(Unit { "l" });

    SECTION("If registered, it returns the address of the registered Unit")
    {
        const auto* searched_unit = kitchen.find_unit("l");
        REQUIRE(searched_unit == &l_unit);
    }
}

TEST_CASE("Units are not relocated in memory when another one is added")
{
    auto kitchen = Kitchen {};

    const auto& first_unit = kitchen.register_unit(Unit { "test" });

    for (auto i = 1; i < 100; ++i)
    {
        // We add many units, to trigger a potential relocation of the elements.
        kitchen.register_unit(Unit { "u" + std::to_string(i) });
    }

    REQUIRE(first_unit.name == "test");
    REQUIRE(kitchen.find_unit("test") == &first_unit);
}
