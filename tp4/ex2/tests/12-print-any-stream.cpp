#include "../src/PhoneNumber.hpp"

#include <catch2/catch_test_macros.hpp>
#include <sstream>

TEST_CASE("L'opérateur de flux de sortie peut écrire dans n'importe quel flux de sortie")
{
    auto pn = PhoneNumber { 1, 64, 0, 66, 73 };

    std::stringstream stream;
    stream << pn;

    // Les nombres sont toujours écrit sur 2 chiffres.
    REQUIRE(stream.str() == "0164006673");
}
