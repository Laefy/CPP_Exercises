#pragma once

#define STB_IMAGE_IMPLEMENTATION
#define STB_DEFINE
#include "../extern/stb_image/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../extern/stb_image/stb_image_write.h"


#include <stdint.h>
#include <array>
#include <string>
#include <iostream>

template <typename P, size_t W, size_t H>
struct Image;


namespace lib
{
    
    uint8_t
    rgb_to_grayscale(const uint8_t r,
                     const uint8_t g,
                     const uint8_t b)
    {
        // cannot produce anything out of [0,255]
        // even with float imprecision
        // (theoric max: 253.215)
        return uint8_t(float(r)*0.299f 
                       + float(g)*0.58f
                       + float(b)*0.114f);
    }

    std::array<uint8_t, 3>
    grayscale_to_rgb(const uint8_t gray)
    {
        // cannot produce anything out of [0,255]
        // even with float imprecision
        // (theoric max: 253.215)
        const float gr = float(gray);
        return {
            uint8_t(std::min(gr/0.299f, 255.f)),
            uint8_t(std::min(gr/0.580f, 255.f)),
            uint8_t(std::min(gr/0.114f, 255.f))
        };
    }
/** Mix the color 1 ontop of the color 2 */
    std::array<uint8_t, 4>
    mix_color(const uint8_t r1, const uint8_t g1, const uint8_t b1, const uint8_t a1,
              const uint8_t r2, const uint8_t g2, const uint8_t b2, const uint8_t a2)
    {
        const double w1 = double(a1)/255.0*(1.0-double(a2)/255.0);
        const double w2 = double(a2)/255.0;
        const uint32_t denom = std::max(1.0, w1 + w2);
    
        const auto & interp = [&](const uint32_t v1,
                                  const uint32_t v2)
        {
            return uint8_t(( double(v1)*w1 + double(v2)*w2)/denom);
        };
        return {
            interp(r1,r2),
            interp(g1,g2),
            interp(b1,b2),
            interp(a1,a2)
        };
    }
          
    template<typename P, size_t W, size_t H>
    Image<P,W,H>
    load(const std::string & path)
    {
        int w, h, c;
        const uint8_t * data = stbi_load(path.c_str(),
                                         &w, &h, &c, 0);
        Image<P,W,H> img = {};
        if(data == NULL)
        {
            std::cout << "Could not find image '" << path << "'" << std::endl;
            exit(1);
        }
        else if (w!=W || h != H || c != sizeof(P))
        {
            std::cout << "Could not open image '"
                      << path << "' with the dimensions ("
                      << W <<"," << H << ","
                      << sizeof(P)<<"), found ("
                      << w <<","<<h<<","<< c  << ")" << std::endl;
        }
        else
        {
            for (size_t i = 0; i < W; ++i)
            {
                for (size_t j = 0; j < H; ++j)
                {
                    const uint8_t * pixel_ptr = data + ((j%h)*w + (i%w))*c;
                    img(i,j) = *reinterpret_cast<const P *>(pixel_ptr);
                }
            }
        }
        return img;
    
    }

    template<typename P, size_t W, size_t H>
    void
    save(const Image<P,W,H> &img,
         const std::string & path)
    {
        const auto data = reinterpret_cast<const uint8_t *>(&img);
        stbi_write_png(path.c_str(), W, H, sizeof(P), data, W*sizeof(P));
    }

    
}
