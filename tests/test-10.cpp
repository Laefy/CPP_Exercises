#include <PlushStore.hpp>

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Test 10 - "
          "Lorsqu'ils produisent des peluches, les magasins gagnent de l'experience.")
{
    auto plush_store = PlushStore { "Growing plush store" };
    plush_store.loan(100);

    plush_store.make_plush(20);
    REQUIRE(plush_store.get_experience() == 1);
 
    plush_store.make_plush(10);
    REQUIRE(plush_store.get_experience() == 2);

    plush_store.make_plush(70);
    REQUIRE(plush_store.get_experience() == 3);
}

TEST_CASE("Test 10 - "
          "La fonction make_plush retourne la valeur de la peluche fabriquee, qui vaut au minimum la valeur investie.")
{
    auto plush_store = PlushStore { "Growing plush store" };
    plush_store.loan(40);

    const auto value_1 = plush_store.make_plush(20);
    REQUIRE(value_1 >= 20);
    
    const auto value_2 = plush_store.make_plush(10);
    REQUIRE(value_2 >= 10);
    
    const auto value_3 = plush_store.make_plush(20);
    REQUIRE(value_3 >= 10);
}

TEST_CASE("Test 10 - "
          "Plus un magasin a de l'experience, plus ses peluches ont de la valeur.")
{
    auto plush_store = PlushStore { "Growing plush store" };
    plush_store.loan(100);

    // Par exemple, une formule qui fonctionne :
    // valeur finale <- valeur investie + max(exp, exp * valeur investie / 100)
    const auto value_1 = plush_store.make_plush(10);
    const auto value_2 = plush_store.make_plush(10);
    const auto value_3 = plush_store.make_plush(10);
    REQUIRE(value_1 < value_2);
    REQUIRE(value_2 < value_3);
}

