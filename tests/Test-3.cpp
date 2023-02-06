#include <Pokeball.h>
#include <Pokemon.h>

#include <catch2/catch_test_macros.hpp>
#include <memory>
#include <utility>

TEST_CASE("3a. There exists a type `PokemonPtr` that represents a pointer to a Pokemon")
{
    PokemonPtr no_pokemon = nullptr;
}

TEST_CASE("3b. Pokemons can be stored in Pokeballs")
{
    PokemonPtr pikachu    = std::make_unique<Pokemon>("Pikachu");
    const auto pikachu_id = pikachu->id();

    auto pokeball = Pokeball {};
    REQUIRE(pokeball.empty() == true);

    pokeball.store(std::move(pikachu));
    REQUIRE(pokeball.empty() == false);

    const auto& pokemon = pokeball.pokemon();
    REQUIRE(pokemon.id() == pikachu_id);
}
