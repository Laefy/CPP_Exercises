#include <PC.h>
#include <Pokeball.h>
#include <Pokemon.h>
#include <Trainer.h>

#include <catch2/catch_test_macros.hpp>
#include <memory>
#include <string>
#include <utility>

TEST_CASE("11. A trainer can retrieve their Pokemons from the PC")
{
    auto pc    = PC {};
    auto sacha = Trainer { "Sacha", pc };

    const auto& sacha_pokeballs = sacha.pokeballs();

    auto        bulbizarre         = std::make_unique<Pokemon>("Bulbizarre");
    const auto* bulbizarre_address = bulbizarre.get();
    sacha.capture(std::move(bulbizarre));
    
    const auto bulbizarre_idx = 0;
    sacha.store_in_pc(bulbizarre_idx);

    SECTION("A trainer can retrieve their Pokemons by name")
    {
        REQUIRE(pc.pokemons().empty() == false);
        REQUIRE(sacha_pokeballs[bulbizarre_idx].empty() == true);

        pc.give_back(sacha, "Bulbizarre");

        REQUIRE(pc.pokemons().empty() == true);
        REQUIRE(sacha_pokeballs[bulbizarre_idx].empty() == false);
        REQUIRE(&sacha_pokeballs[bulbizarre_idx].pokemon() == bulbizarre_address);
    }

    SECTION("When a trainer retrieves its Pokemon, it goes in the next empty Pokeball")
    {
        auto        carapuce = std::make_unique<Pokemon>("Carapuce");
        const auto* carapuce_address = carapuce.get();
        sacha.capture(std::move(carapuce));

        const auto carapuce_idx   = 0;
        const auto next_empty_idx = 1;
        REQUIRE(sacha_pokeballs[carapuce_idx].empty() == false);
        REQUIRE(sacha_pokeballs[next_empty_idx].empty() == true);

        pc.give_back(sacha, "Bulbizarre");
        REQUIRE(sacha_pokeballs[carapuce_idx].empty() == false);
        REQUIRE(&sacha_pokeballs[carapuce_idx].pokemon() == carapuce_address);
        REQUIRE(sacha_pokeballs[next_empty_idx].empty() == false);
        REQUIRE(&sacha_pokeballs[next_empty_idx].pokemon() == bulbizarre_address);
    }

    SECTION("If a trainer with no empty Pokeball tries to retrieve a Pokemon, nothing happens")
    {
        for (auto i = 0; i < 6; ++i)
        {
            auto pokemon = std::make_unique<Pokemon>("Pokemon_" + std::to_string(i));
            sacha.capture(std::move(pokemon));
            
            REQUIRE(sacha_pokeballs[i].empty() == false);
        }

        REQUIRE(pc.pokemons().empty() == false);
        REQUIRE(pc.pokemons()[0].get() == bulbizarre_address);
        pc.give_back(sacha, "Bulbizarre");
        
        REQUIRE(pc.pokemons().empty() == false);
        REQUIRE(pc.pokemons()[0].get() == bulbizarre_address);
    }

    SECTION("If a trainer tries to steal the Pokemon of someone else, nothing happens")
    {
        auto pierre = Trainer { "Pierre", pc };

        auto carapuce = std::make_unique<Pokemon>("Carapuce");
        pierre.capture(std::move(carapuce));
        
        const auto carapuce_idx = 0;
        pierre.store_in_pc(carapuce_idx);

        REQUIRE(pc.pokemons().size() == 2);
        REQUIRE(sacha_pokeballs[0].empty() == true);

        pc.give_back(sacha, "Carapuce");

        REQUIRE(pc.pokemons().size() == 2);
        REQUIRE(sacha_pokeballs[0].empty() == true);
    }
}
