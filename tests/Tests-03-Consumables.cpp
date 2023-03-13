#include "../lib/Consumable.hpp"
#include "../lib/Ingredient.hpp"
#include "../src/Kitchen.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("The Kitchen can create random Consumables")
{
    auto kitchen = Kitchen {};

    SECTION("If the Kitchen has no ingredients, it always returns std::nullopt")
    {
        for (auto i = 0; i < 10; ++i)
        {
            const auto consumable = kitchen.make_random_consumable(3.f, 12);
            REQUIRE(consumable == std::nullopt);
        }
    }

    SECTION("If the Kitchen has one or many ingredients, it returns a consumable of one of these types")
    {
        const auto& piece_unit = kitchen.register_unit(Unit { "" });

        const auto ingredients =
            std::set { &kitchen.register_ingredient(Ingredient { "Apple", piece_unit }),
                       &kitchen.register_ingredient(Ingredient { "Biscuit", piece_unit }),
                       &kitchen.register_ingredient(Ingredient { "Yoghourt", piece_unit }) };

        for (auto i = 0; i < 10; ++i)
        {
            const auto consumable = kitchen.make_random_consumable(3.f, 12);
            REQUIRE(consumable != std::nullopt);
            REQUIRE(ingredients.count(&consumable->ingredient.get()) == 1u);
            REQUIRE(consumable->quantity == 3.f);
            REQUIRE(consumable->expiration_time == 12);
        }
    }
}
