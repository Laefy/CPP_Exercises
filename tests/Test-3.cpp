#include <Card.hpp>

#include <catch2/catch_test_macros.hpp>

// Compétences travaillées :
// - définir des fonctions-membres constantes

TEST_CASE("3. Getter functions do not modify the instance")
{
    const auto card = Card { "DUSA-FR100", CardType::Monster };
    REQUIRE(card.get_id() == "DUSA-FR100");
    REQUIRE(card.get_type() == CardType::Monster);
    REQUIRE(card.get_name() == "");
    REQUIRE(card.get_description() == "");
}
