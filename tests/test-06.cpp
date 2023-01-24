#include <PlushStore.hpp>

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Test 06 - "
          "La classe `PlushStore` prend en parametre de construction le nom de la boutique.")
{
    const auto plush_store_1 = PlushStore { "Plushes Are Fluffeez" };
    REQUIRE(plush_store_1.get_name() == "Plushes Are Fluffeez");

    const auto plush_store_2 = PlushStore { "Kiut Animalzzz" };
    REQUIRE(plush_store_2.get_name() == "Kiut Animalzzz");
    
    REQUIRE(plush_store_1.get_name() == "Plushes Are Fluffeez");
    REQUIRE(plush_store_2.get_name() == "Kiut Animalzzz");
}
