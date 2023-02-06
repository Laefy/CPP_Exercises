#include <PC.h>
#include <Pokeball.h>
#include <Pokemon.h>
#include <Trainer.h>

#include <catch2/catch_test_macros.hpp>
#include <memory>
#include <utility>

TEST_CASE("10. A trainer can store Pokemons in the PC")
{
    auto pc    = PC {};
    auto sacha = Trainer { "Sacha", pc };

    auto       bulbizarre    = std::make_unique<Pokemon>("Bulbizarre");
    const auto bulbizarre_id = bulbizarre->id();
    sacha.capture(std::move(bulbizarre));
    
    auto       carapuce    = std::make_unique<Pokemon>("Carapuce");
    const auto carapuce_id = carapuce->id();
    sacha.capture(std::move(carapuce));
    
    const auto bulbizarre_idx = 0;
    const auto carapuce_idx   = 1;

    SECTION("PC is empty is no Pokemon has been stored in it")
    {
        REQUIRE(pc.pokemons().empty() == true);
    }

    SECTION("If the first Pokemon is stored, it goes in the PC, and the other Pokemons stay at their places")
    {
        sacha.store_in_pc(bulbizarre_idx);

        REQUIRE(pc.pokemons().empty() == false);
        REQUIRE(pc.pokemons()[0]->id() == bulbizarre_id);

        REQUIRE(sacha.pokeballs()[bulbizarre_idx].empty() == true);
        REQUIRE(sacha.pokeballs()[carapuce_idx].empty() == false);
    }

    SECTION("Pokemons are stored in the PC in the same order they were added in it")
    {
        sacha.store_in_pc(bulbizarre_idx);
        sacha.store_in_pc(carapuce_idx);

        REQUIRE(pc.pokemons().empty() == false);
        REQUIRE(pc.pokemons()[0]->id() == bulbizarre_id);
        REQUIRE(pc.pokemons()[1]->id() == carapuce_id);

        REQUIRE(sacha.pokeballs()[bulbizarre_idx].empty() == true);
        REQUIRE(sacha.pokeballs()[carapuce_idx].empty() == true);
    }
}
