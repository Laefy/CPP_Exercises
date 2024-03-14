#include "../lib/InstanceCounter.hpp"
#include "../src/alias.hpp" // Fichier à remplir

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Definir les alias PTR_ALIAS1 et PTR_ALIAS2 dans ../src/alias.hpp.  Il n'y a pas besoin "
          "d'implémenter des classes !")
{
    {
        PTR_ALIAS1 ptr { new InstanceCounter {} };
        auto&      InstanceCounter = *ptr; // Verifie que ptr peut-être déréférencé
        REQUIRE(1 == InstanceCounter::constructions());
        REQUIRE(0 == InstanceCounter::deletions());
    }
    REQUIRE(1 == InstanceCounter::deletions());
    // Vérifie que l'InstanceCounter pointé a bien été détruit.

    {
        PTR_ALIAS2 ptr             = new InstanceCounter {};
        auto&      InstanceCounter = *ptr; // Verifie que ptr peut-être déréférencé
        REQUIRE(2 == InstanceCounter::constructions());
        REQUIRE(1 == InstanceCounter::deletions());
    }
    REQUIRE(1 == InstanceCounter::deletions());
    // Vérifie que l'InstanceCounter n'a PAS été détruit
}
