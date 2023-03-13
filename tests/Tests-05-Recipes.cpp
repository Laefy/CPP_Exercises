#include "../lib/Ingredient.hpp"
#include "../lib/Recipe.hpp"
#include "../lib/Unit.hpp"
#include "../src/Kitchen.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Recipes can be registered in the Kitchen")
{
    auto kitchen = Kitchen {};

    const auto& piece_unit = kitchen.register_unit(Unit { "" });
    const auto& g_unit     = kitchen.register_unit(Unit { "g" });
    const auto& cl_unit    = kitchen.register_unit(Unit { "cl" });

    const auto& tomato     = kitchen.register_ingredient(Ingredient { "Tomato", piece_unit });
    const auto& mozzarella = kitchen.register_ingredient(Ingredient { "Mozarella", g_unit });
    const auto& vinegar    = kitchen.register_ingredient(Ingredient { "Vinegar", cl_unit });
    const auto& olive_oil  = kitchen.register_ingredient(Ingredient { "Olive Oil", cl_unit });

    kitchen.register_recipe(
        Recipe { "Tomato-Mozzarella",
                 { { &tomato, 2.f }, { &mozzarella, 100.f }, { &vinegar, 5.f }, { &olive_oil, 10.f } } });

    SECTION("Recipe can be retrieved from their name")
    {
        REQUIRE(kitchen.find_recipe("Tomato-Mozzarella") != nullptr);
    }

    SECTION("If not registered, the Kitchen returns nullptr")
    {
        REQUIRE(kitchen.find_recipe("Pizza") == nullptr);
    }
}

TEST_CASE("The Kitchen can compute the list of missing Ingredients for a given Recipe")
{
    auto kitchen = Kitchen {};

    const auto& piece_unit = kitchen.register_unit(Unit { "" });
    const auto& g_unit     = kitchen.register_unit(Unit { "g" });
    const auto& cl_unit    = kitchen.register_unit(Unit { "cl" });

    const auto& tomato     = kitchen.register_ingredient(Ingredient { "Tomato", piece_unit });
    const auto& mozzarella = kitchen.register_ingredient(Ingredient { "Mozarella", g_unit });
    const auto& vinegar    = kitchen.register_ingredient(Ingredient { "Vinegar", cl_unit });
    const auto& olive_oil  = kitchen.register_ingredient(Ingredient { "Olive Oil", cl_unit });

    const auto recipe =
        Recipe { "Tomato-Mozzarella",
                 { { &tomato, 2.f }, { &mozzarella, 100.f }, { &vinegar, 5.f }, { &olive_oil, 10.f } } };

    kitchen.store_in_cupboard(Consumable { tomato, 1.f, 5u });
    kitchen.store_in_cupboard(Consumable { olive_oil, 200.f, std::nullopt });
    kitchen.store_in_cupboard(Consumable { vinegar, 4.5f, 0u });
    kitchen.store_in_cupboard(Consumable { tomato, 0.5f, 1u });

    const auto missing_quantities = kitchen.compute_missing_quantities(recipe);

    SECTION("If the ingredient is missing, then it maps to the quantity required in the Recipe")
    {
        REQUIRE(missing_quantities.at(&mozzarella) == 100.f);
    }

    SECTION("If the ingredient is partially missing, only the missing quantity is returned")
    {
        REQUIRE(missing_quantities.at(&tomato) == 2.f - (1.f + 0.5f));
    }

    SECTION("If the ingredient is outdated, then it is as if it was not present at all")
    {
        REQUIRE(missing_quantities.at(&vinegar) == 5.f);
    }

    SECTION("If the ingredient is already present, then it doesn't appear at all")
    {
        REQUIRE(missing_quantities.count(&olive_oil) == 0u);
    }
}

TEST_CASE("The Kitchen provides the list of Recipes that required only available Ingredients")
{
    auto kitchen = Kitchen {};

    const auto& piece_unit = kitchen.register_unit(Unit { "" });
    const auto& g_unit     = kitchen.register_unit(Unit { "g" });
    const auto& cl_unit    = kitchen.register_unit(Unit { "cl" });

    const auto& tomato     = kitchen.register_ingredient(Ingredient { "Tomato", piece_unit });
    const auto& mozzarella = kitchen.register_ingredient(Ingredient { "Mozarella", g_unit });
    const auto& vinegar    = kitchen.register_ingredient(Ingredient { "Vinegar", cl_unit });
    const auto& olive_oil  = kitchen.register_ingredient(Ingredient { "Olive Oil", cl_unit });
    const auto& egg        = kitchen.register_ingredient(Ingredient { "Egg", piece_unit });
    const auto& salad      = kitchen.register_ingredient(Ingredient { "Salad", g_unit });
    const auto& nuts       = kitchen.register_ingredient(Ingredient { "Nuts", g_unit });

    kitchen.register_recipe(
        Recipe { "Tomato-Mozzarella",
                 { { &tomato, 2.f }, { &mozzarella, 100.f }, { &vinegar, 5.f }, { &olive_oil, 10.f } } });

    kitchen.register_recipe(
        Recipe { "Light Salad", { { &tomato, 1.f }, { &salad, 100.f }, { &vinegar, 10.f } } });

    kitchen.register_recipe(Recipe {
        "Funky Salad",
        { { &salad, 80.f }, { &nuts, 40.f }, { &mozzarella, 20.f }, { &egg, 1.f }, { &olive_oil, 10.f } } });

    SECTION("If no Ingredients are available, no Recipes are returned")
    {
        REQUIRE(kitchen.compute_feasible_recipes().empty() == true);
    }

    SECTION("If all Ingredients are available, all Recipes are returned")
    {
        kitchen.store_in_cupboard(Consumable { tomato, 100.f, std::nullopt });
        kitchen.store_in_cupboard(Consumable { olive_oil, 200.f, std::nullopt });
        kitchen.store_in_cupboard(Consumable { mozzarella, 500.f, std::nullopt });
        kitchen.store_in_cupboard(Consumable { vinegar, 400.f, std::nullopt });
        kitchen.store_in_cupboard(Consumable { nuts, 200.f, std::nullopt });
        kitchen.store_in_cupboard(Consumable { salad, 200.f, std::nullopt });
        kitchen.store_in_cupboard(Consumable { egg, 100.f, std::nullopt });

        const auto recipes = kitchen.compute_feasible_recipes();
        REQUIRE(recipes.count(kitchen.find_recipe("Tomato-Mozzarella")) == 1u);
        REQUIRE(recipes.count(kitchen.find_recipe("Light Salad")) == 1u);
        REQUIRE(recipes.count(kitchen.find_recipe("Funky Salad")) == 1u);
    }

    SECTION("If an Ingredient is missing, the Recipe is not returned")
    {
        kitchen.store_in_cupboard(Consumable { olive_oil, 200.f, std::nullopt });
        kitchen.store_in_cupboard(Consumable { mozzarella, 500.f, std::nullopt });
        kitchen.store_in_cupboard(Consumable { salad, 200.f, std::nullopt });
        kitchen.store_in_cupboard(Consumable { egg, 100.f, std::nullopt });

        const auto recipes = kitchen.compute_feasible_recipes();
        REQUIRE(recipes.count(kitchen.find_recipe("Funky Salad")) == 0u);
    }

    SECTION("If the quantity of an Ingredient is too low, the Recipe is not returned")
    {
        kitchen.store_in_cupboard(Consumable { tomato, 0.5f, std::nullopt });
        kitchen.store_in_cupboard(Consumable { vinegar, 400.f, std::nullopt });
        kitchen.store_in_cupboard(Consumable { salad, 200.f, std::nullopt });

        const auto recipes = kitchen.compute_feasible_recipes();
        REQUIRE(recipes.count(kitchen.find_recipe("Light Salad")) == 0u);
    }

    SECTION("If an Ingredient is outdated, the Recipe is not returned")
    {
        kitchen.store_in_cupboard(Consumable { tomato, 2.f, std::nullopt });
        kitchen.store_in_cupboard(Consumable { vinegar, 400.f, std::nullopt });
        kitchen.store_in_cupboard(Consumable { olive_oil, 400.f, std::nullopt });
        kitchen.store_in_cupboard(Consumable { mozzarella, 50.f, std::nullopt });
        kitchen.store_in_cupboard(Consumable { mozzarella, 150.f, 0 });
        kitchen.store_in_cupboard(Consumable { salad, 200.f, std::nullopt });

        const auto recipes = kitchen.compute_feasible_recipes();
        REQUIRE(recipes.count(kitchen.find_recipe("Tomato-Mozzarella")) == 0u);
        REQUIRE(recipes.count(kitchen.find_recipe("Light Salad")) == 1u);
    }
}
