#include "../src/pixels.hpp"

#include <catch2/catch_test_macros.hpp>


TEST_CASE("Implementation of the function from<A, B> converting B to A")
{
    
    const RGBA rgba = {250, 105, 50, 160};
    const RGB rgb = {66, 166, 30};
    const Luma luma = {100};

    const RGB rgb_from_rgba = from<RGB, RGBA>(rgba);
    const RGBA rgba_from_rgb = from<RGBA, RGB>(rgb);
    const Luma luma_from_rgb = from<Luma, RGB>(rgb);
    
    REQUIRE(rgb_from_rgba.r == rgba.r);
    REQUIRE(rgb_from_rgba.g == rgba.g);
    REQUIRE(rgb_from_rgba.b == rgba.b);
    
    REQUIRE(rgba_from_rgb.r == rgb.r);
    REQUIRE(rgba_from_rgb.g == rgb.g);
    REQUIRE(rgba_from_rgb.b == rgb.b);
    REQUIRE(rgba_from_rgb.a == 255);

    REQUIRE(luma_from_rgb.gray == lib::rgb_to_grayscale(rgb.r, rgb.g, rgb.b));
    
}


