#include "../src/PhoneBook.hpp"
#include "../src/PhoneBookEntry.hpp"
#include "../src/PhoneNumber.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("La fonction add_entry ajoute l'entrée uniquement si elle est valide, et retourne si l'ajout a pu "
          "être effectué")
{
    auto phone_book = PhoneBook {};

    const auto pauline_number = PhoneNumber { 1, 2, 3, 4, 5 };
    const auto pauline_added  = phone_book.add_entry(PhoneBookEntry { "Pauline", pauline_number });
    REQUIRE(true == pauline_added);

    const auto jean_number = PhoneNumber { 5, 4, 3, 2, -1 };
    const auto jean_added  = phone_book.add_entry(PhoneBookEntry { "Jean", jean_number });
    REQUIRE(true == jean_added);
}
