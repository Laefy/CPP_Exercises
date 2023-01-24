#include <PlushStore.hpp>

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Test 07 - "
          "Par defaut, les magasins de peluches n'ont ni argent, ni stock.")
{
    const auto plush_store = PlushStore { "Very Very Broke Store" };
    REQUIRE(plush_store.get_wealth_amount() == 0);
    REQUIRE(plush_store.get_stock_size() == 0);
}
