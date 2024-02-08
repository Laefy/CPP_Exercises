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

TEST_CASE("Lorsqu'on utilise get_number, la donnée pointée n'est pas désinstanciée par d'éventuelles "
          "insertions dans le PhoneBook")
{
    auto phone_book = PhoneBook {};

    phone_book.add_entry(PhoneBookEntry { "Pauline", PhoneNumber { 1, 64, 12, 66, 73 } });

    // On récupère le numéro de Pauline
    const auto* pauline_phone = phone_book.get_number("Pauline");

    // On ajoute quelques nouvelles entrées
    const auto other_phone = PhoneNumber { 1, 2, 3, 4, 5 };
    phone_book.add_entry(PhoneBookEntry { "Jean", other_phone });
    phone_book.add_entry(PhoneBookEntry { "Marcel", other_phone });
    phone_book.add_entry(PhoneBookEntry { "Maria", other_phone });

    // On vérifie que le contenu du pointeur pauline_phone contient bien le résultat attendu
    // Attention, si la donnée est déjà désinstanciée, l'instruction ci-dessous produit un undefined behavior.
    const auto is_still_the_same_number =
        are_phone_numbers_equal(*pauline_phone, PhoneNumber { 1, 64, 12, 66, 73 });

    REQUIRE(true == is_still_the_same_number);
}
