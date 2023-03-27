#include "../src/pixels.hpp"
#include "../src/image.hpp"

#include <catch2/catch_test_macros.hpp>


TEST_CASE("Blending (RGBA + RGB) => RGBA")
{
    const RGBA a = RGBA{105, 37, 150, 34};
    const RGB  b = RGB {5, 137, 54};
    const RGBA pix = a + b;

    const std::array<uint8_t, 4> raw = lib::mix_color(a.r, a.g, a.b, a.a,
                                                 b.r, b.g, b.b, 255);
    const RGBA truth = reinterpret_cast<const RGBA &>(raw);
    REQUIRE(truth.r == pix.r);
    REQUIRE(truth.g == pix.g);
    REQUIRE(truth.b == pix.b);
    REQUIRE(truth.a == pix.a);
}

