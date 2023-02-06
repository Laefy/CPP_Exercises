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

TEST_CASE("1c. Whenever a Pokemon is constructed, it is assigned an identifier that gets incremented each time.")
{
    const auto pikachu = Pokemon { "Pikachu" };
    const auto bulbizarre = Pokemon { "Bulbizarre" };
    const auto pikachu_copy = pikachu;

    REQUIRE(pikachu.id() == 0);
    REQUIRE(bulbizarre.id() == 1);
    REQUIRE(pikachu_copy.id() == 2);

    auto pikachu_becoming_bulbizarre = pikachu;
    REQUIRE(pikachu_becoming_bulbizarre.id() == 3);
    
    pikachu_becoming_bulbizarre = bulbizarre;
    REQUIRE(pikachu_becoming_bulbizarre.id() == 3);
}