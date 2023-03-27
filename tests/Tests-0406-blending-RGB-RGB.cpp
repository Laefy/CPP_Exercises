#include "../src/pixels.hpp"
#include "../src/image.hpp"

#include <catch2/catch_test_macros.hpp>


TEST_CASE("Blending (RGBA + RGB) => RGBA")
{
    const RGB a = RGB{105, 37, 150};
    const RGB b = RGB{5, 137, 54};
    const RGB ab = a + b;
    const RGB ba = b + a;

    const auto [abr, abg, abb, aba] = lib::mix_color(a.r, a.g, a.b, 255,
                                                     b.r, b.g, b.b, 255);
    const auto [bar, bag, bab, baa] = lib::mix_color(b.r, b.g, b.b, 255,
                                                     a.r, a.g, a.b, 255);
    REQUIRE(abr == ab.r);
    REQUIRE(abg == ab.g);
    REQUIRE(abb == ab.b);
    REQUIRE(bar == ba.r);
    REQUIRE(bag == ba.g);
    REQUIRE(bab == ba.b);
}

