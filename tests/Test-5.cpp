#include <Monster.hpp>

#include <catch2/catch_test_macros.hpp>

// Compétences travaillées :
// - appeler depuis une fonction-membre fille l'implémentation de la classe-mère

TEST_CASE("5. The description of a Monster is generated from the base description and its specific attributes")
{
    auto monster = Monster { "DUSA-FR100", "Magicien Sombre", Attribute::Dark, "Magicien", 2500, 2100 };
    monster.set_description("Mage suprême en terme d'attaque et de défense.");

    const Card& monster_as_card = monster;
    REQUIRE(monster_as_card.get_description() == "Mage suprême en terme d'attaque et de défense.");

    const Monster& const_monster = monster;
    REQUIRE(const_monster.get_description() == "[Magicien]\nMage suprême en terme d'attaque et de défense.\nATK/2500 DEF/2100");
}
