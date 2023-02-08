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
    const auto first_id = pikachu.id();

    const auto bulbizarre = Pokemon { "Bulbizarre" };
    const auto pikachu_copy = pikachu;

    REQUIRE(bulbizarre.id() == first_id + 1);
    REQUIRE(pikachu_copy.id() == first_id + 2);

    auto pikachu_becoming_bulbizarre = pikachu;
    REQUIRE(pikachu_becoming_bulbizarre.id() == first_id + 3);

    pikachu_becoming_bulbizarre = bulbizarre;
    REQUIRE(pikachu_becoming_bulbizarre.id() == first_id + 3);
}