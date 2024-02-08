#include "../src/PhoneBookEntry.hpp"
#include "../src/PhoneNumber.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Il existe une classe PhoneBookEntry dont le constructeur attend le nom d'une personne et un "
          "numéro de téléphone")
{
    auto entry = PhoneBookEntry { "Marcel", PhoneNumber { 1, 64, 0, 66, 73 } };
}
