#include "../src/pixels.hpp"
#include "../src/image.hpp"

#include <catch2/catch_test_macros.hpp>

#include <iostream>

TEST_CASE("Blending (Luma + RGBA) => RGB")
{
    const Luma a = Luma{109};
    const RGBA b = RGBA{105, 37, 150, 34};
    const RGB pix = a + b;
    
    const RGBA c = from<RGBA, Luma>(a);
    const auto [tr,tg,tb,ta]
        = lib::mix_color(c.r, c.g, c.b, c.a,
                         b.r, b.g, b.b, b.a);
    
    const RGB truth = {tr,tg,tb};
    REQUIRE(truth.r == pix.r);
    REQUIRE(truth.g == pix.g);
    REQUIRE(truth.b == pix.b);
    
}

