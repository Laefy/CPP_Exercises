#include <Board.hpp>
#include <Card.hpp>
#include <Monster.hpp>
#include <Spell.hpp>
#include <Trap.hpp>

#include <catch2/catch_test_macros.hpp>
#include <memory>
#include <random>

// Compétences travaillées :
// - utiliser des smart-pointers
// - overloader des fonctions

class CardFactory
{
public:
    std::unique_ptr<Monster> make_random_monster()
    {
        return std::make_unique<Monster>(make_random_id(),
                                         "Monster",
                                         make_random_attribute(),
                                         "Type",
                                         make_random_int(0, 3000),
                                         make_random_int(0, 3000));
    }

    std::unique_ptr<Spell> make_random_spell()
    {
        return std::make_unique<Spell>(make_random_id(),
                                       "Spell",
                                       make_random_spell_type());
    }

    std::unique_ptr<Trap> make_random_trap()
    {
        return std::make_unique<Trap>(make_random_id(),
                                      "Trap",
                                      make_random_trap_type());
    }

private:
    int make_random_int(int min, int max)
    {
        auto distribution = std::uniform_int_distribution { min, max };
        return distribution(_generator);
    }

    std::string make_random_id()
    {
        return "ID-FR" + std::to_string(make_random_int(1, 2000));
    }

    Attribute make_random_attribute()
    {
        return static_cast<Attribute>(make_random_int(0, 6));
    }

    SpellType make_random_spell_type()
    {
        return static_cast<SpellType>(make_random_int(0, 4));
    }

    TrapType make_random_trap_type()
    {
        return static_cast<TrapType>(make_random_int(0, 2));
    }

    std::mt19937 _generator { std::random_device{} () };
};

TEST_CASE("9a. There is a class named Board")
{
    [[maybe_unused]] const auto board = Board {};
}

TEST_CASE("9b. For each type of card, there is a limit that can be placed on the board")
{
    auto factory = CardFactory {};
    auto board = Board {};

    SECTION("At most 5 monsters can be placed simultaneously")
    {
        for (auto i = 0; i < 5; ++i)
        {
            REQUIRE(board.put(factory.make_random_monster()) == true);
        }

        REQUIRE(board.put(factory.make_random_monster()) == false);
    }

    SECTION("At most 5 spells can be placed simultaneously")
    {
        for (auto i = 0; i < 5; ++i)
        {
            REQUIRE(board.put(factory.make_random_spell()) == true);
        }

        REQUIRE(board.put(factory.make_random_spell()) == false);
    }

    SECTION("At most 5 traps can be placed simultaneously")
    {
        for (auto i = 0; i < 5; ++i)
        {
            REQUIRE(board.put(factory.make_random_trap()) == true);
        }

        REQUIRE(board.put(factory.make_random_trap()) == false);
    }

    SECTION("Spells and traps share the same limit (at most 5 spells OR traps)")
    {
        for (auto i = 0; i < 2; ++i)
        {
            REQUIRE(board.put(factory.make_random_spell()) == true);
            REQUIRE(board.put(factory.make_random_trap()) == true);
        }

        REQUIRE(board.put(factory.make_random_trap()) == true);
        REQUIRE(board.put(factory.make_random_spell()) == false);
    }
}
