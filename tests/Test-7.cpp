#include <Trap.hpp>

#include <catch2/catch_test_macros.hpp>

// Compétences travaillées :
// - définir une énumération
// - définir une classe-fille
// - invoquer le constructeur de la classe-mère

TEST_CASE("7a. There is an enumeration named TrapType and a function to_string converting their values to string")
{
    REQUIRE(to_string(TrapType::Normal) == "Normal");
    REQUIRE(to_string(TrapType::Continuous) == "Continuous");
    REQUIRE(to_string(TrapType::Counter) == "Counter");
}

TEST_CASE("7b. Trap is a Card with additional properties")
{
    auto trap = Trap { "CP07-FR020", "Anti-Contre", TrapType::Counter };
    trap.set_description("Annulez l'activation d'une Carte Contre-Piège et détruisez-la.");
    REQUIRE(trap.get_trap_type() == TrapType::Counter);

    const Card& trap_as_card = trap;
    REQUIRE(trap_as_card.get_id() == "CP07-FR020");
    REQUIRE(trap_as_card.get_type() == CardType::Trap);
    REQUIRE(trap_as_card.get_name() == "Anti-Contre");
}
