#include <PlushStore.hpp>

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Test 09 - "
          "1. En consommant leur argent, les magasins de peluches peuvent produire des peluches.")
{
    auto plush_store = PlushStore { "Very Productive Plushes Store" };
    plush_store.loan(100);

    plush_store.make_plush(20);
    REQUIRE(plush_store.get_stock_size() == 1);
    REQUIRE(plush_store.get_wealth_amount() == 80);
 
    plush_store.make_plush(10);
    REQUIRE(plush_store.get_stock_size() == 2);
    REQUIRE(plush_store.get_wealth_amount() == 70);

    plush_store.make_plush(70);
    REQUIRE(plush_store.get_stock_size() == 3);
    REQUIRE(plush_store.get_wealth_amount() == 0);
}

TEST_CASE("Test 09 - "
          "2. Si il n'a plus d'argent du tout, alors le magasin ne peut plus produire de peluches.")
{
    auto plush_store = PlushStore { "Broke Again" };
    plush_store.loan(10);

    // On essaye de confectionner une peluche qui coute 5€ ==> ok car on a 10€.
    plush_store.make_plush(5);
    REQUIRE(plush_store.get_stock_size() == 1);
    REQUIRE(plush_store.get_wealth_amount() == 5);
 
    // On essaye de confectionner une peluche qui coute 10€ ==> ok car on n'est pas en faillite, mais elle sera toute naze cette peluche.
    plush_store.make_plush(10);
    REQUIRE(plush_store.get_stock_size() == 2);
    REQUIRE(plush_store.get_wealth_amount() == 0);

    // On essaye de confectionner une peluche qui coute 2€ ==> pas ok car on a plus de sous et que les employés sont en grève.
    plush_store.make_plush(2);
    REQUIRE(plush_store.get_stock_size() == 2);
    REQUIRE(plush_store.get_wealth_amount() == 0);
}

