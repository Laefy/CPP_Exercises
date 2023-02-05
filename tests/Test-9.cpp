#include <PC.h>
#include <Pokeball.h>
#include <Pokemon.h>
#include <Trainer.h>

#include <catch2/catch_test_macros.hpp>
#include <memory>
#include <utility>

TEST_CASE("9. A Pokemon knows its trainer")
{
    auto bulbizarre = std::make_unique<Pokemon>("Bulbizarre");
    REQUIRE(bulbizarre->trainer() == nullptr);

    auto pc    = PC {};
    auto sacha = Trainer { "Sacha", pc };

    sacha.capture(std::move(bulbizarre));
    REQUIRE(sacha.pokeballs()[0].pokemon().trainer() == &sacha);
}