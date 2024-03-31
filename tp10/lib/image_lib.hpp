#pragma once

#include "stb_image.h"
#include "stb_image_write.h"

#include <array>
#include <cstdint>
#include <filesystem>
#include <iostream>
#include <string>

template <typename P, size_t W, size_t H>
struct Image;

namespace image_lib {

uint8_t                rgb_to_grayscale(const uint8_t r, const uint8_t g, const uint8_t b);
std::array<uint8_t, 3> grayscale_to_rgb(const uint8_t gray);
std::array<uint8_t, 4> mix_color(const uint8_t r1, const uint8_t g1, const uint8_t b1, const uint8_t a1,
                                 const uint8_t r2, const uint8_t g2, const uint8_t b2, const uint8_t a2);

template <typename P, size_t W, size_t H>
Image<P, W, H> load(const std::filesystem::path& path)
{
    int            w, h, c;
    const uint8_t* data = stbi_load(path.c_str(), &w, &h, &c, 0);

    Image<P, W, H> img = {};
    if (data == NULL)
    {
        std::cout << "Could not find image '" << path << "'" << std::endl;
        exit(1);
    }
    std::cout << "Loaded " << path << " with dims (" << w << "," << h << ") and " << c << " channels."
              << std::endl;
    if (w != W || h != H || c != sizeof(P))
    {
        std::cout << "Could not open image '" << path << "' with the dimensions (" << W << "," << H << ","
                  << sizeof(P) << "), found (" << w << "," << h << "," << c << ")" << std::endl;
    }
    else
    {
        for (size_t i = 0; i < W; ++i)
        {
            for (size_t j = 0; j < H; ++j)
            {
                const uint8_t* pixel_ptr = data + ((j % h) * w + (i % w)) * c;
                img(i, j)                = *reinterpret_cast<const P*>(pixel_ptr);
            }
        }
    }
    return img;
}

template <typename P, size_t W, size_t H>
void save(const Image<P, W, H>& img, const std::filesystem::path& path)
{
    std::filesystem::create_directories(path.parent_path());

    const auto data = reinterpret_cast<const uint8_t*>(&img);
    if (stbi_write_png(path.c_str(), W, H, sizeof(P), data, W * sizeof(P)))
    {
        std::cout << "Saved image at '" << path << "'" << std::endl;
    }
}

} // namespace image_lib