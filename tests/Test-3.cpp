#include <Pokeball.h>
#include <Pokemon.h>

#include <catch2/catch_test_macros.hpp>
#include <memory>
#include <utility>

TEST_CASE("3. Pokemons can be stored in Pokeballs")
{
    auto pikachu = std::make_unique<Pokemon>("Pikachu");

    auto pokeball = Pokeball {};
    REQUIRE(pokeball.empty() == true);

    pokeball.store(std::move(pikachu));
    REQUIRE(pokeball.empty() == false);

    const auto& pokemon = pokeball.pokemon();
    REQUIRE(pokemon.name() == "Pikachu");
}
