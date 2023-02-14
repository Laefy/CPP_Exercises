#include <Spell.hpp>

#include <catch2/catch_test_macros.hpp>

// Compétences travaillées :
// - définir une énumération
// - définir une classe-fille
// - invoquer le constructeur de la classe-mère

TEST_CASE("6a. There is an enumeration named SpellType and a function to_string converting their values to string")
{
    REQUIRE(to_string(SpellType::Normal) == "Normal");
    REQUIRE(to_string(SpellType::Equip) == "Equip");
    REQUIRE(to_string(SpellType::Continuous) == "Continuous");
    REQUIRE(to_string(SpellType::QuickPlay) == "Quick-Play");
    REQUIRE(to_string(SpellType::Field) == "Field");
}

TEST_CASE("6b. Spell is a Card with additional properties")
{
    auto spell = Spell { "AST-FR089", "Magie Economique", SpellType::Continuous };
    spell.set_description("Vous n'avez pas à payer de Life Points pour activer une Carte Magie.");
    REQUIRE(spell.get_spell_type() == SpellType::Continuous);

    const Card& spell_as_card = spell;
    REQUIRE(spell_as_card.get_id() == "AST-FR089");
    REQUIRE(spell_as_card.get_type() == CardType::Spell);
    REQUIRE(spell_as_card.get_name() == "Magie Economique");
}
