#include <PC.h>

#include <catch2/catch_test_macros.hpp>

TEST_CASE("4. PCs are constructed with 0 Pokemon inside")
{
    auto pc = PC {};

    const auto& pokemons = pc.pokemons();
    REQUIRE(pokemons.empty() == true);
}
