#include "../src/PhoneNumber.hpp"

#include <catch2/catch_test_macros.hpp>
#include <string>

TEST_CASE("Si l'opérateur d'indice est appelé en dehors de la bonne plage, il renvoie -1")
{
    auto pn = PhoneNumber { 1, 64, 12, 66, 73 };

    auto before = pn[-1];
    REQUIRE(-1 == before);

    auto after = pn[5];
    REQUIRE(-1 == after);
}
