#include "../lib/image_lib.hpp"
#include "image.hpp"
#include "pixels.hpp"

#include <cassert>

int main()
{
    // N'hésitez pas à commenter les lignes que vous n'avez pas encore implémentées pour tester les autres.

    const RGBA rgba = { 250, 105, 50, 160 };
    const RGB  rgb  = { 66, 166, 30 };
    const Luma luma = { 42 };

    const RGB rgb_from_rgba = convert<RGB, RGBA>(rgba);
    assert(rgb_from_rgba.r == rgba.r);
    assert(rgb_from_rgba.g == rgba.g);
    assert(rgb_from_rgba.b == rgba.b);

    const RGBA rgba_from_rgb = convert<RGBA, RGB>(rgb);
    assert(rgba_from_rgb.r == rgb.r);
    assert(rgba_from_rgb.g == rgb.g);
    assert(rgba_from_rgb.b == rgb.b);
    assert(rgba_from_rgb.a == 255);

    const Luma luma_from_rgb = convert<Luma, RGB>(rgb);
    assert(luma_from_rgb.gray == image_lib::rgb_to_grayscale(rgb.r, rgb.g, rgb.b));

    const Luma luma_from_rgba = convert<Luma, RGBA>(rgba);
    assert(luma_from_rgba.gray == image_lib::rgb_to_grayscale(rgba.r, rgba.g, rgba.b));

}