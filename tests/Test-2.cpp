#include <Pokeball.h>

#include <catch2/catch_test_macros.hpp>

TEST_CASE("2a. Pokeballs are empty by default")
{
    auto pokeball = Pokeball {};
    REQUIRE(pokeball.empty() == true);
}

TEST_CASE("2b. Querying whether a Pokeball is empty does not modify the Pokeball")
{
    const auto pokeball = Pokeball {};
    REQUIRE(pokeball.empty() == true);
}
