#include <Kid.hpp>
#include <Plush.hpp>
#include <PlushStore.hpp>

#include <catch2/catch_test_macros.hpp>
#include <sstream>

TEST_CASE("Test 12 - "
          "La classe Kid peut etre affichee dans un stream de sortie")
{
    const auto dany = Kid { "Dany", 12 };

    auto stream = std::stringstream {};
    stream << dany;
    REQUIRE(stream.str() == "Dany has 12 euros.");
}
