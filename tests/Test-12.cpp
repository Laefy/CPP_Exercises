#include <PC.h>
#include <Pokedex.h>
#include <Pokemon.h>
#include <Trainer.h>

#include <catch2/catch_test_macros.hpp>
#include <algorithm>
#include <memory>
#include <string>

TEST_CASE("12a. A Pokedex references all the instances of a Pokemon type")
{
    auto pokedex = Pokedex {};

    auto pikachu_1 = std::make_unique<Pokemon>("Pikachu");
    auto pikachu_2 = std::make_unique<Pokemon>("Pikachu");
    auto pikachu_3 = std::make_unique<Pokemon>("Pikachu");
    
    auto bulbizarre_1 = std::make_unique<Pokemon>("Bulbizarre");
    auto bulbizarre_2 = std::make_unique<Pokemon>("Bulbizarre");

    pokedex.add(*pikachu_1);
    pokedex.add(*pikachu_2);
    pokedex.add(*pikachu_3);

    pokedex.add(*bulbizarre_1);
    pokedex.add(*bulbizarre_2);

    SECTION("It returns an empty collection if there is no Pokemon")
    {
        const auto missingnos = pokedex.find("Missigno"); 
        REQUIRE(missingnos.empty() == true);
    }

    SECTION("It returns a collection with the correct instances if the Pokemon exists")
    {
        const auto pikachus = pokedex.find("Pikachu");
        REQUIRE(pikachus.size() == 3);

        const auto pikachu_it_1 = std::find(pikachus.begin(), pikachus.end(), pikachu_1.get());
        REQUIRE(pikachu_it_1 != pikachus.end());
        
        const auto bulbizarres = pokedex.find("Bulbizarre");
        REQUIRE(bulbizarres.size() == 2);

        const auto bulbizarre_it_2 = std::find(bulbizarres.begin(), bulbizarres.end(), bulbizarre_2.get());
        REQUIRE(bulbizarre_it_2 != bulbizarres.end());
    }
}

TEST_CASE("12b. Each trainer has their own Pokedex referencing all their captured Pokemons")
{
    auto pc    = PC {};
    auto sacha = Trainer { "Sacha", pc };

    for (auto i = 0; i < 10; ++ i)
    {
        sacha.capture(std::make_unique<Pokemon>("Pokemon"));
    }

    const auto& pokedex = sacha.pokedex();
    const auto& pokemons = pokedex.find("Pokemon");

    SECTION("Pokemons have been added in the Pokedex")
    {
        REQUIRE(pokemons.size() == 10);
    }

    SECTION("Pokemons in Pokeballs are referenced")
    {
        for (const auto& pokeball: sacha.pokeballs())
        {
            if (!pokeball.empty())
            {
                const auto it = std::find(pokemons.begin(), pokemons.end(), &pokeball.pokemon());
                REQUIRE(it != pokemons.end());
            }
        }
    }
    
    SECTION("Pokemons in PC are referenced")
    {
        for (const auto& pokemon_in_pc: pc.pokemons())
        {
            const auto it = std::find(pokemons.begin(), pokemons.end(), pokemon_in_pc.get());
            REQUIRE(it != pokemons.end());
        }
    }
}

