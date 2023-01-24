#include <Plush.hpp>

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Test 01 - "
          "La classe `Plush` est instanciable par defaut.")
{
    auto plush [[maybe_unused]] = Plush {};
}
