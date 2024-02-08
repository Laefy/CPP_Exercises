#include "../src/PhoneBookEntry.hpp"
#include "../src/PhoneNumber.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Les accesseurs renvoient leurs résultats par référence")
{
    auto entry = PhoneBookEntry { "Marcel", PhoneNumber { 1, 64, 0, 66, 73 } };

    const auto& n1 = entry.get_name();
    const auto& n2 = entry.get_name();

    const auto& pn1 = entry.get_number();
    const auto& pn2 = entry.get_number();

    // Si on retourne par référence, alors les adresses sont les mêmes.
    REQUIRE(&n1 == &n2);
    REQUIRE(&pn1 == &pn2);
}
