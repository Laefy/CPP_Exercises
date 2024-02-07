#include "../src/PhoneBook.hpp"
#include "../src/PhoneBookEntry.hpp"
#include "../src/PhoneNumber.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("PhoneBook contient une fonction add_entry pour ajouter des PhoneBookEntry à l'instance")
{
    auto       phone_book   = PhoneBook {};
    const auto phone_number = PhoneNumber { 1, 2, 3, 4, 5 };

    phone_book.add_entry(PhoneBookEntry { "Pauline", phone_number });
    phone_book.add_entry(PhoneBookEntry { "Jean", phone_number });
    phone_book.add_entry(PhoneBookEntry { "Maria", phone_number });
}
