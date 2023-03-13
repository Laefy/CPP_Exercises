#include "../lib/Consumable.hpp"
#include "../lib/Cupboard.hpp"
#include "../src/Kitchen.hpp"

#include <catch2/catch_test_macros.hpp>
#include <type_traits>
#include <unordered_set>

TEST_CASE("The Kitchen contains a Cupboard")
{
    const auto kitchen  = Kitchen {};
    auto&      cupboard = kitchen.get_cupboard();

    REQUIRE(std::is_same_v<decltype(cupboard), const Cupboard&>);
}

TEST_CASE("Consumables can be stored in the Kitchen's Cupboard")
{
    auto        kitchen  = Kitchen {};
    const auto& cupboard = kitchen.get_cupboard();

    const auto& piece_unit = kitchen.register_unit(Unit { "" });
    const auto& apple      = kitchen.register_ingredient(Ingredient { "Apple", piece_unit });
    const auto& biscuit    = kitchen.register_ingredient(Ingredient { "Biscuit", piece_unit });
    const auto& yoghourt   = kitchen.register_ingredient(Ingredient { "Yoghourt", piece_unit });

    kitchen.store_in_cupboard(Consumable { apple, 3.f, 5 });
    kitchen.store_in_cupboard(Consumable { yoghourt, 1.f, 2 });
    kitchen.store_in_cupboard(Consumable { apple, 2.f, 3 });
    kitchen.store_in_cupboard(Consumable { biscuit, 3.f, std::nullopt });

    SECTION("They are stored in the order they were added")
    {
        const auto& consumables = cupboard.consumables;
        REQUIRE(consumables.size() == 4);

        REQUIRE(consumables.at(0) == Consumable { apple, 3.f, 5 });
        REQUIRE(consumables.at(1) == Consumable { yoghourt, 1.f, 2 });
        REQUIRE(consumables.at(2) == Consumable { apple, 2.f, 3 });
        REQUIRE(consumables.at(3) == Consumable { biscuit, 3.f, std::nullopt });
    }

    SECTION("When time passed, the Consumable gets closer to its expiration date")
    {
        const auto& consumables = cupboard.consumables;

        kitchen.wait_time(2);

        REQUIRE(consumables.at(0).expiration_time == 3);
        REQUIRE(consumables.at(1).expiration_time == 0);
        REQUIRE(consumables.at(2).expiration_time == 1);
        REQUIRE(consumables.at(3).expiration_time == std::nullopt);

        kitchen.wait_time(1);

        REQUIRE(consumables.at(0).expiration_time == 2);
        REQUIRE(consumables.at(1).expiration_time == 0);
        REQUIRE(consumables.at(2).expiration_time == 0);
        REQUIRE(consumables.at(3).expiration_time == std::nullopt);

        kitchen.wait_time(5);

        REQUIRE(consumables.at(0).expiration_time == 0);
        REQUIRE(consumables.at(1).expiration_time == 0);
        REQUIRE(consumables.at(2).expiration_time == 0);
        REQUIRE(consumables.at(3).expiration_time == std::nullopt);
    }
}

TEST_CASE("We can query the total quantity of a specific ingredient")
{
    auto kitchen = Kitchen {};

    const auto& piece_unit = kitchen.register_unit(Unit { "" });
    const auto& apple      = kitchen.register_ingredient(Ingredient { "Apple", piece_unit });
    const auto& biscuit    = kitchen.register_ingredient(Ingredient { "Biscuit", piece_unit });

    kitchen.store_in_cupboard(Consumable { apple, 3.f, 5 });
    kitchen.store_in_cupboard(Consumable { apple, 6.5f, 5 });
    kitchen.store_in_cupboard(Consumable { biscuit, 1.f, 3 });
    kitchen.store_in_cupboard(Consumable { biscuit, 2.f, 0 });

    SECTION("If there are several Consumables of this type, their quantities are summed")
    {
        REQUIRE(kitchen.compute_quantity(apple) == 3.f + 6.5f);
    }

    SECTION("If Consumables are outdated, their quantity is ignored")
    {
        REQUIRE(kitchen.compute_quantity(biscuit) == 1.f);
    }
}

TEST_CASE("We can compute the total quantity of Consumables verifying a predicate")
{
    auto kitchen = Kitchen {};

    const auto& piece_unit = kitchen.register_unit(Unit { "" });
    const auto& apple      = kitchen.register_ingredient(Ingredient { "Apple", piece_unit });
    const auto& biscuit    = kitchen.register_ingredient(Ingredient { "Biscuit", piece_unit });

    kitchen.store_in_cupboard(Consumable { apple, 3.f, 5 });
    kitchen.store_in_cupboard(Consumable { apple, 6.5f, 5 });
    kitchen.store_in_cupboard(Consumable { biscuit, 2.f, 0 });
    kitchen.store_in_cupboard(Consumable { biscuit, 1.f, 3 });
    kitchen.store_in_cupboard(Consumable { apple, 1.f, 0 });

    auto const is_expired = [](const Consumable& c) { return c.expiration_time == 0u; };
    REQUIRE(kitchen.compute_quantity(is_expired) == 2.f + 1.f);

    SECTION("If there are several Consumables of this type, their quantities are summed")
    {
        REQUIRE(kitchen.compute_quantity(apple) == 3.f + 6.5f);
    }

    SECTION("If Consumables are outdated, their quantity is ignored")
    {
        REQUIRE(kitchen.compute_quantity(biscuit) == 1.f);
    }
}

TEST_CASE("The Kitchen can be tied up")
{
    auto        kitchen  = Kitchen {};
    const auto& cupboard = kitchen.get_cupboard();

    const auto& piece_unit = kitchen.register_unit(Unit { "" });
    const auto& apple      = kitchen.register_ingredient(Ingredient { "Apple", piece_unit });
    const auto& biscuit    = kitchen.register_ingredient(Ingredient { "Biscuit", piece_unit });
    const auto& yoghourt   = kitchen.register_ingredient(Ingredient { "Yoghourt", piece_unit });

    SECTION("Consumables with no quantities are removed")
    {
        kitchen.store_in_cupboard(Consumable { apple, 3.f, 5 });
        kitchen.store_in_cupboard(Consumable { yoghourt, 0.f, 4 });
        kitchen.store_in_cupboard(Consumable { biscuit, 1.f, 3 });

        kitchen.tidy_up();

        const auto as_set =
            std::unordered_set<Consumable>(cupboard.consumables.begin(), cupboard.consumables.end());
        REQUIRE(as_set.size() == 2);

        // Only the yoghourt was removed.
        REQUIRE(as_set.count(Consumable { apple, 3.f, 5 }) == 1u);
        REQUIRE(as_set.count(Consumable { yoghourt, 0.f, 4 }) == 0u);
        REQUIRE(as_set.count(Consumable { biscuit, 1.f, 3 }) == 1u);
    }

    SECTION("Consumables with the same type and expiration time are regrouped")
    {
        kitchen.store_in_cupboard(Consumable { apple, 3.f, 5 });
        kitchen.store_in_cupboard(Consumable { yoghourt, 2.f, std::nullopt });
        kitchen.store_in_cupboard(Consumable { apple, 2.f, std::nullopt });
        kitchen.store_in_cupboard(Consumable { apple, 1.f, 5 });
        kitchen.store_in_cupboard(Consumable { yoghourt, 2.f, std::nullopt });

        kitchen.tidy_up();

        const auto as_set =
            std::unordered_set<Consumable>(cupboard.consumables.begin(), cupboard.consumables.end());
        REQUIRE(as_set.size() == 3);

        // Apples with expiration_time == 5 were merged.
        REQUIRE(as_set.count(Consumable { apple, 3.f + 1.f, 5 }) == 1u);
        REQUIRE(as_set.count(Consumable { apple, 2.f, std::nullopt }) == 1u);
        REQUIRE(as_set.count(Consumable { apple, 3.f, 5 }) == 0u);
        REQUIRE(as_set.count(Consumable { apple, 1.f, 5 }) == 0u);

        // Yoghourt with expiration_time == nullopt were merged.
        REQUIRE(as_set.count(Consumable { yoghourt, 2.f + 2.f, std::nullopt }) == 1u);
        REQUIRE(as_set.count(Consumable { yoghourt, 2.f, std::nullopt }) == 0u);
        REQUIRE(as_set.count(Consumable { yoghourt, 2.f, std::nullopt }) == 0u);
    }

    SECTION("Outdated Consumables are removed")
    {
        kitchen.store_in_cupboard(Consumable { apple, 3.f, 0 });
        kitchen.store_in_cupboard(Consumable { yoghourt, 1.f, 4 });
        kitchen.store_in_cupboard(Consumable { apple, 8.f, std::nullopt });
        kitchen.store_in_cupboard(Consumable { biscuit, 1.f, 0 });

        kitchen.tidy_up();

        const auto as_set =
            std::unordered_set<Consumable>(cupboard.consumables.begin(), cupboard.consumables.end());
        REQUIRE(as_set.size() == 2);

        REQUIRE(as_set.count(Consumable { apple, 3.f, 0 }) == 0u);
        REQUIRE(as_set.count(Consumable { yoghourt, 1.f, 4 }) == 1u);
        REQUIRE(as_set.count(Consumable { apple, 8.f, std::nullopt }) == 1u);
        REQUIRE(as_set.count(Consumable { biscuit, 1.f, 0 }) == 0u);
    }
}
