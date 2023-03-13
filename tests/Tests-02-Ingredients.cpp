#include "../lib/Ingredient.hpp"
#include "../lib/Unit.hpp"
#include "../src/Kitchen.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Ingredients can be registered in the Kitchen")
{
    auto kitchen = Kitchen {};

    const auto& piece_unit = kitchen.register_unit(Unit { "" });

    const auto& apple = kitchen.register_ingredient(Ingredient { "Apple", piece_unit });
    REQUIRE(apple.name == "Apple");
    REQUIRE(&apple.unit.get() == &piece_unit);

    const auto& tomato = kitchen.register_ingredient(Ingredient { "Tomato", piece_unit });
    REQUIRE(tomato.name == "Tomato");
    REQUIRE(&tomato.unit.get() == &piece_unit);
}

TEST_CASE("Ingredients can be retrieved from the Kitchen with their name")
{
    auto kitchen = Kitchen {};

    SECTION("If not registered, it returns null")
    {
        const auto* searched_ingredient = kitchen.find_ingredient("Floor");
        REQUIRE(searched_ingredient == nullptr);
    }

    const auto& g_unit = kitchen.register_unit(Unit { "g" });
    const auto& floor  = kitchen.register_ingredient(Ingredient { "Floor", g_unit });

    SECTION("If registered, it returns the address of the registered Ingredient")
    {
        const auto* searched_ingredient = kitchen.find_ingredient("Floor");
        REQUIRE(searched_ingredient == &floor);
    }

    SECTION("The search ignores the case")
    {
        const auto* searched_ingredient = kitchen.find_ingredient("flOOr");
        REQUIRE(searched_ingredient == &floor);
    }
}

TEST_CASE("Ingredients are not relocated in memory when another one is added")
{
    auto kitchen = Kitchen {};

    const auto& unit             = kitchen.register_unit(Unit { "" });
    const auto& first_ingredient = kitchen.register_ingredient(Ingredient { "Test", unit });

    for (auto i = 1; i < 100; ++i)
    {
        // We add many units, to trigger a potential relocation of the elements.
        kitchen.register_ingredient(Ingredient { "I" + std::to_string(i), unit });
    }

    REQUIRE(first_ingredient.name == "Test");
    REQUIRE(kitchen.find_ingredient("test") == &first_ingredient);
}
