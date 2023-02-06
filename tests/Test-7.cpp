#include <PC.h>
#include <Pokeball.h>
#include <Trainer.h>

#include <catch2/catch_test_macros.hpp>

TEST_CASE("7. Trainers start with 6 empty pokeballs")
{
    auto       pc    = PC {};
    const auto sacha = Trainer { "Sacha", pc };

    const auto& pokeballs = sacha.pokeballs();
    REQUIRE(pokeballs.size() == 6u);

    for (const auto& pokeball : pokeballs)
    {
        REQUIRE(pokeball.empty() == true);
    }
}
