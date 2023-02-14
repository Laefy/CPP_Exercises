#include <Card.hpp>
#include <Monster.hpp>
#include <Spell.hpp>
#include <Trap.hpp>

#include <catch2/catch_test_macros.hpp>

// Compétences travaillées :
// - définir un membre protégé

TEST_CASE("8a. There is a field named `_symbol` in Card, that is accessible from child-classes directly")
{
    struct ChildCard : Card
    {
        ChildCard()
        : Card { "SOME-ID", CardType::Spell }
        {
            _symbol = "symbol";
        }
    };

    const auto card = ChildCard {};
    REQUIRE(card.get_symbol() == "symbol");
}

TEST_CASE("8b. The symbol of a Monster is the symbol of its attribute")
{
    const auto monster_1 = Monster { "SDMY-FR020", "Kuriboh", Attribute::Dark, "Démon/Effet", 300, 200 };
    REQUIRE(monster_1.get_symbol() == u8"闇");

    const auto monster_2 = Monster { "LCJW-FR222", "Dompteur de Monstres", Attribute::Earth, "Guerrier", 1800, 1600 };
    REQUIRE(monster_2.get_symbol() == u8"地");

    const auto monster_3 = Monster { "SR02-FR006", "Dragon du Brasier Sombre", Attribute::Fire, "Dragon/Effet", 1200, 1000 };
    REQUIRE(monster_3.get_symbol() == u8"炎");
}

TEST_CASE("8c. The symbol of a Spell is always the Spell symbol")
{
    const auto spell_symbol = u8"魔";

    const auto spell = Spell { "5DS3-FR027", "Réincarnation de Monstre", SpellType::Normal };
    REQUIRE(spell.get_symbol() == spell_symbol);
}

TEST_CASE("8d. The symbol of a Trap is always the Trap symbol")
{
    const auto trap_symbol = u8"罠";

    const auto trap = Trap { "YS17-FR034", "Force de Miroir", TrapType::Normal };
    REQUIRE(trap.get_symbol() == trap_symbol);
}
