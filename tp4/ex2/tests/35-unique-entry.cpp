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

TEST_CASE(
    "L'entrée n'est pas ajoutée si elle existe déjà (c'est-à-dire qu'elle a le même nom) dans le répertoire")
{
    auto       phone_book = PhoneBook {};
    const auto n1         = PhoneNumber { 1, 2, 3, 4, 5 };
    const auto n2         = PhoneNumber { 5, 4, 3, 2, 1 };

    // Pauline n'est pas encore présente
    const auto r1 = phone_book.add_entry(PhoneBookEntry { "Pauline", n1 });
    REQUIRE(r1 == true);

    // Jean non plus
    const auto r2 = phone_book.add_entry(PhoneBookEntry { "Jean", n1 });
    REQUIRE(r2 == true);

    // Pauline est déjà présente
    const auto r3 = phone_book.add_entry(PhoneBookEntry { "Pauline", n2 });
    REQUIRE(r3 == false);

    // Marcel n'est pas encore là
    const auto r4 = phone_book.add_entry(PhoneBookEntry { "Marcel", n2 });
    REQUIRE(r4 == true);

    // Pour Pauline, c'est le premier numéro qui a été ajouté
    const PhoneNumber* pauline_number = phone_book.get_number("Pauline");
    REQUIRE(nullptr != pauline_number);
    REQUIRE(true == are_phone_numbers_equal(*pauline_number, n1));
}
