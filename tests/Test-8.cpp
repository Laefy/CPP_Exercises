#include <PC.h>
#include <Pokeball.h>
#include <Pokemon.h>
#include <Trainer.h>

#include <catch2/catch_test_macros.hpp>
#include <memory>
#include <utility>

TEST_CASE("8. A trainer can catch a pokemon")
{
    auto pc    = PC {};
    auto sacha = Trainer { "Sacha", pc };

    SECTION("It goes in its next empty pokeball if any")
    {
        auto       pikachu    = std::make_unique<Pokemon>("Pikachu");
        const auto pikachu_id = pikachu->id();

        auto       bulbizarre    = std::make_unique<Pokemon>("Bulbizarre");
        const auto bulbizarre_id = bulbizarre->id();

        const auto& pokeballs = sacha.pokeballs();

        REQUIRE(pokeballs[0].empty() == true);
        sacha.capture(std::move(pikachu));
        REQUIRE(pokeballs[0].empty() == false);
        REQUIRE(pokeballs[0].pokemon().id() == pikachu_id);

        REQUIRE(pokeballs[1].empty() == true);
        sacha.capture(std::move(bulbizarre));
        REQUIRE(pokeballs[1].empty() == false);
        REQUIRE(pokeballs[1].pokemon().id() == bulbizarre_id);
    }

    SECTION("If no more empty pokeballs, it goes to the PC")
    {
        for (auto i = 0; i < 6; ++i)
        {
            auto pokemon = std::make_unique<Pokemon>("Pokemon_" + std::to_string(i));
            sacha.capture(std::move(pokemon));
        }

        REQUIRE(sacha.pokeballs()[5].empty() == false);
        REQUIRE(pc.pokemons().empty() == true);

        auto       dracaufeu    = std::make_unique<Pokemon>("Dracaufeu");
        const auto dracaufeu_id = dracaufeu->id();
        sacha.capture(std::move(dracaufeu));

        REQUIRE(pc.pokemons().empty() == false);
        REQUIRE(pc.pokemons()[0]->id() == dracaufeu_id);
    }
}