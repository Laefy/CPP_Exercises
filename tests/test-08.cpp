#include <PlushStore.hpp>

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Test 08 - "
          "Les magasins de peluches peuvent emprunter de l'argent a 10 pour cent d'interets.")
{
    auto plush_store = PlushStore { "Not That Broke Anymore" };

    plush_store.loan(100);
    REQUIRE(plush_store.get_wealth_amount() == 100);
    REQUIRE(plush_store.get_debt_amount() == 110);
    
    plush_store.loan(300);
    REQUIRE(plush_store.get_wealth_amount() == 400);
    REQUIRE(plush_store.get_debt_amount() == 440);
}
