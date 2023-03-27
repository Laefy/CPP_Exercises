#include "../src/pixels.hpp"
#include "../src/image.hpp"

#include <catch2/catch_test_macros.hpp>

#include <iostream>

TEST_CASE("Blending (Luma + RGBA) => RGBA")
{
    const Luma a = Luma{109};
    const RGBA b = RGBA{105, 37, 150, 34};
    const RGBA pix = a + b;
    
    const RGBA c = from<RGBA, Luma>(a);
    const std::array<uint8_t, 4> raw = lib::mix_color(c.r, c.g, c.b, c.a,
                                                 b.r, b.g, b.b, b.a);
    const RGBA truth = reinterpret_cast<const RGBA &>(raw);
    REQUIRE(truth.r == pix.r);
    REQUIRE(truth.g == pix.g);
    REQUIRE(truth.b == pix.b);
    REQUIRE(truth.a == pix.a);
    
}

