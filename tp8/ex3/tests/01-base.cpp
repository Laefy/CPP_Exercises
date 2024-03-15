#include "../src/Base.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Il existe une classe abstraite Base qui possède une fonction-membre is_null()")
{
    const Base* b = nullptr; // Ceci est une astuce pour utiliser le type Base
    if (b != nullptr)        // bien qu'on ne puisse pas l'instancier.
    {
        bool s = b->is_null();
    }

    // Cet test vérifie que la classe Base est abstraite.
    REQUIRE(std::is_abstract<Base>() == true);
}
