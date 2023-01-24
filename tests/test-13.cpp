#include <Plush.hpp>
#include <PlushStore.hpp>

#include <catch2/catch_test_macros.hpp>
#include <optional>

TEST_CASE("Test 13 - "
          "1. On peut acheter une peluche du magasin si et seulement si on dispose de suffisament d'argent pour.")
{
    auto plush_store = PlushStore { "Fluffy" };
    plush_store.loan(10);
    
    const auto value = plush_store.make_plush(10);

    // La fonction buy doit renvoyer un objet de type std::optional<Plush>.
    const auto no_plush = plush_store.buy(5);
    REQUIRE(no_plush == std::nullopt);
    REQUIRE(plush_store.get_stock_size() == 1);
    REQUIRE(plush_store.get_wealth_amount() == 0);
    
    const auto plush = plush_store.buy(50);
    REQUIRE(plush != std::nullopt);
    REQUIRE(plush->get_cost() == value);
    REQUIRE(plush_store.get_stock_size() == 0);
    REQUIRE(plush_store.get_wealth_amount() == value);
}

TEST_CASE("Test 13 - "
          "2. Quand on achete une peluche, on prend systematiquement la moins chere du magasin.")
{
    auto plush_store = PlushStore { "Fluffy" };
    plush_store.loan(60);
    
    const auto v1 = plush_store.make_plush(10);
    const auto v2 = plush_store.make_plush(30);
    const auto v3 = plush_store.make_plush(20);
    
    const auto plush_1 = plush_store.buy(50);
    REQUIRE(plush_1 != std::nullopt);
    REQUIRE(plush_1->get_cost() == v1);
    REQUIRE(plush_store.get_stock_size() == 2);
    REQUIRE(plush_store.get_wealth_amount() == v1);
    
    const auto plush_3 = plush_store.buy(50);
    REQUIRE(plush_3 != std::nullopt);
    REQUIRE(plush_3->get_cost() == v3);
    REQUIRE(plush_store.get_stock_size() == 1);
    REQUIRE(plush_store.get_wealth_amount() == v1 + v3);
    
    const auto plush_2 = plush_store.buy(50);
    REQUIRE(plush_2 != std::nullopt);
    REQUIRE(plush_2->get_cost() == v2);
    REQUIRE(plush_store.get_stock_size() == 0);
    REQUIRE(plush_store.get_wealth_amount() == v1 + v2 + v3);
}

