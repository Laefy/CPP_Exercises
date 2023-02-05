#include <PC.h>
#include <Trainer.h>

#include <catch2/catch_test_macros.hpp>

TEST_CASE("6. Trainers are constructed with their name and they are assigned a PC")
{
    auto       pc     = PC {};
    const auto sacha  = Trainer { "Sacha", pc };
    const auto ondine = Trainer { "Ondine", pc };

    REQUIRE(sacha.name() == "Sacha");
    REQUIRE(ondine.name() == "Ondine");
}
