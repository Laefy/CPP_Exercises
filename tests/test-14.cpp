#include <Kid.hpp>
#include <Plush.hpp>
#include <PlushStore.hpp>

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Test 14 - "
          "Un enfant peut acheter une peluche au magasin.")
{
    auto plush_store = PlushStore { "Fluffy" };
    plush_store.loan(10);
    plush_store.make_plush(10);

    auto kid = Kid { "Dany", 20 };
    kid.buy_plush(plush_store);
    REQUIRE(kid.get_money() <= 10);
    REQUIRE(plush_store.get_wealth_amount() >= 10);
    REQUIRE(plush_store.get_stock_size() == 0);
}
