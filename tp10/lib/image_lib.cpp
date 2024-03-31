#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "image_lib.hpp"

template <typename P, size_t W, size_t H>
struct Image;

namespace image_lib {

uint8_t rgb_to_grayscale(const uint8_t r, const uint8_t g, const uint8_t b)
{
    // cannot produce anything out of [0,255]
    // even with float imprecision
    // (theoric max: 253.215)
    return uint8_t(float(r) * 0.299f + float(g) * 0.58f + float(b) * 0.114f);
}

std::array<uint8_t, 3> grayscale_to_rgb(const uint8_t gray)
{
    // cannot produce anything out of [0,255]
    // even with float imprecision
    // (theoric max: 253.215)
    const float gr = float(gray);
    return { uint8_t(std::min(gr / 0.299f, 255.f)), uint8_t(std::min(gr / 0.580f, 255.f)),
             uint8_t(std::min(gr / 0.114f, 255.f)) };
}

/** Mix the color 1 ontop of the color 2 */
std::array<uint8_t, 4> mix_color(const uint8_t r1, const uint8_t g1, const uint8_t b1, const uint8_t a1,
                                 const uint8_t r2, const uint8_t g2, const uint8_t b2, const uint8_t a2)
{
    const double   w1    = double(a1) / 255.0 * (1.0 - double(a2) / 255.0);
    const double   w2    = double(a2) / 255.0;
    const uint32_t denom = std::max(1.0, w1 + w2);

    const auto& interp = [&](const uint32_t v1, const uint32_t v2)
    { return uint8_t((double(v1) * w1 + double(v2) * w2) / denom); };
    return { interp(r1, r2), interp(g1, g2), interp(b1, b2), interp(a1, a2) };
}

} // namespace image_lib