#include "../src/PhoneBook.hpp"
#include "../src/PhoneBookEntry.hpp"
#include "../src/PhoneNumber.hpp"

#include <catch2/catch_test_macros.hpp>

bool are_phone_numbers_equal(PhoneNumber pn1, PhoneNumber pn2)
{
    for (auto i = 0; i < 5; ++i)
    {
        if (pn1[i] != pn2[i])
        {
            return false;
        }
    }

    return true;
}

TEST_CASE("PhoneBook contient une fonction get_number qui retourne le numéro de la personne demandée, ou "
          "nullptr si elle n'est pas présente")
{
    auto phone_book = PhoneBook {};

    const auto pauline_number = PhoneNumber { 1, 2, 3, 4, 5 };
    phone_book.add_entry(PhoneBookEntry { "Pauline", pauline_number });

    const auto jean_number = PhoneNumber { 5, 4, 3, 2, 1 };
    phone_book.add_entry(PhoneBookEntry { "Jean", jean_number });

    const PhoneNumber* pauline_result = phone_book.get_number("Pauline");
    REQUIRE(pauline_result != nullptr);
    REQUIRE(true == are_phone_numbers_equal(*pauline_result, pauline_number));

    const PhoneNumber* jean_result = phone_book.get_number("Jean");
    REQUIRE(jean_result != nullptr);
    REQUIRE(true == are_phone_numbers_equal(*jean_result, jean_number));

    // Marcel n'est pas dans le répertoire.
    const PhoneNumber* marcel_result = phone_book.get_number("Marcel");
    REQUIRE(marcel_result == nullptr);
}
