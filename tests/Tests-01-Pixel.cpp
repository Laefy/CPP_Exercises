#include "../src/pixels.hpp"

#include <catch2/catch_test_macros.hpp>


TEST_CASE("The 3 pixels structure RGBA RGB Luma are implemented")
{
    const RGBA rgba = {250, 105, 50, 255};
    const RGB rgb = {250, 105, 50};
    const Luma luma = {100};
    REQUIRE(rgba.r == 250);
    REQUIRE(rgba.g == 105);
    REQUIRE(rgba.b == 50);
    REQUIRE(rgba.a == 255);
    REQUIRE(rgb.r == 250);
    REQUIRE(rgb.g == 105);
    REQUIRE(rgb.b == 50);
    REQUIRE(luma.gray == 100);
}

TEST_CASE("The values of the pixels are encoded on one octet")
{
    REQUIRE(sizeof(RGBA) == 4);
    REQUIRE(sizeof(RGB ) == 3);
    REQUIRE(sizeof(Luma) == 1);
}

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

    REQUIRE(luma_from_rgb.gray == rgb_to_grayscale(rgb.r, rgb.g, rgb.b));
    
}

TEST_CASE("Implementation of the function into<A, B> converting A to B")
{
    
    const RGBA rgba = {250, 105, 50, 160};
    const RGB rgb = {66, 166, 30};
    const Luma luma = {100};

    const RGBA rgb_into_rgba = into<RGB, RGBA>(rgb);
    const RGB rgba_into_rgb = into<RGBA, RGB>(rgba);
    const RGB luma_into_rgb = into<Luma, RGB>(luma);
    
    REQUIRE(rgb_into_rgba.r == rgb.r);
    REQUIRE(rgb_into_rgba.g == rgb.g);
    REQUIRE(rgb_into_rgba.b == rgb.b);
    REQUIRE(rgb_into_rgba.a == 255);
    
    REQUIRE(rgba_into_rgb.r == rgba.r);
    REQUIRE(rgba_into_rgb.g == rgba.g);
    REQUIRE(rgba_into_rgb.b == rgba.b);
    
    {
        const auto [r,g,b] = grayscale_to_rgb(luma.gray);
        REQUIRE(luma_into_rgb.r == r);
        REQUIRE(luma_into_rgb.g == g);
        REQUIRE(luma_into_rgb.b == b);
    }
}

