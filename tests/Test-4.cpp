#include <Monster.hpp>

#include <catch2/catch_test_macros.hpp>

// Compétences travaillées :
// - définir une énumération
// - définir une classe-fille
// - invoquer le constructeur de la classe-mère

TEST_CASE("4a. There is an enumeration named Attribute and a function to_symbol converting their values to an UTF-8 character")
{
    // Vous pouvez copier-coller les `u8"..."` directement dans vos fonctions.
    REQUIRE(to_symbol(Attribute::Dark) == u8"闇");
    REQUIRE(to_symbol(Attribute::Divine) == u8"神");
    REQUIRE(to_symbol(Attribute::Earth) == u8"地");
    REQUIRE(to_symbol(Attribute::Fire) == u8"炎");
    REQUIRE(to_symbol(Attribute::Light) == u8"光");
    REQUIRE(to_symbol(Attribute::Water) == u8"水");
    REQUIRE(to_symbol(Attribute::Wind) == u8"風");
}

TEST_CASE("4b. Monster is a Card with additional properties")
{
    const auto atk = 2500;
    const auto def = 2100;
    const auto monster = Monster { "DUSA-FR100", "Magicien Sombre", Attribute::Dark, "Magicien", atk, def };
    REQUIRE(monster.get_attribute() == Attribute::Dark);
    REQUIRE(monster.get_atk() == 2500);
    REQUIRE(monster.get_def() == 2100);

    const Card& monster_as_card = monster;
    REQUIRE(monster_as_card.get_id() == "DUSA-FR100");
    REQUIRE(monster_as_card.get_type() == CardType::Monster);
    REQUIRE(monster_as_card.get_name() == "Magicien Sombre");
}
