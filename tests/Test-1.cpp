#include <Card.hpp>

#include <catch2/catch_test_macros.hpp>

// Compétences travaillées :
// - définir une énumération (voir `enum class`)

TEST_CASE("1. There is an enumeration named CardType and a function to_string converting their values to string")
{
    REQUIRE(to_string(CardType::Monster) == "Monster");
    REQUIRE(to_string(CardType::Spell) == "Spell");
    REQUIRE(to_string(CardType::Trap) == "Trap");
}
