#include <Card.hpp>

#include <catch2/catch_test_macros.hpp>

// Compétences travaillées :
// - définir une classe
// - définir des attributs
// - définir des fonctions-membres
// - utiliser des std::string

TEST_CASE("2. There is a class named Card with a certain number of properties")
{
    auto card = Card { "SS02-FRA01", CardType::Monster };
    REQUIRE(card.get_id() == "SS02-FRA01");
    REQUIRE(card.get_type() == CardType::Monster);
    REQUIRE(card.get_name() == "");
    REQUIRE(card.get_description() == "");

    card.set_name("Dragon Blanc aux Yeux Bleus");
    REQUIRE(card.get_name() == "Dragon Blanc aux Yeux Bleus");

    const auto description = "Ce dragon légendaire est un puissant moteur de destruction. "
                             "Rares sont ceux qui ont survécu à cette terrifiante créature quasiment invincible pour en parler.";
    card.set_description(description);
    REQUIRE(card.get_description() == description);
}
