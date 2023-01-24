#include <Kid.hpp>

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Test 11 - "
          "La classe `Kid` s'instancie avec le nom de l'enfant et la quantite d'argent de poche dont il dispose")
{
    const auto dany = Kid { "Dany", 12 };
    REQUIRE(dany.get_name() == "Dany");
    REQUIRE(dany.get_money() == 12);
}
