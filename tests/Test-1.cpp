#include <Pokemon.h>

#include <catch2/catch_test_macros.hpp>

TEST_CASE("1a. Pokemons can be constructed with their name")
{
    auto pikachu = Pokemon { "Pikachu" };
    auto bulbizarre = Pokemon { "Bulbizarre" };

    REQUIRE(pikachu.name() == "Pikachu");
    REQUIRE(bulbizarre.name() == "Bulbizarre");
}

TEST_CASE("1b. Querying the name of a Pokemon does not modify the Pokemon")
{
    const auto pikachu = Pokemon { "Pikachu" };
    const auto bulbizarre = Pokemon { "Bulbizarre" };

    REQUIRE(pikachu.name() == "Pikachu");
    REQUIRE(bulbizarre.name() == "Bulbizarre");
}
