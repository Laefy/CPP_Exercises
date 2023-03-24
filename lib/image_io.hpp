#pragma once

#include <array>
#include <stdint.h>
#include <cstddef>
#include <string>
#include <iostream>
#include <functional>
#include <cassert>
#include <memory>

#include "lib.hpp"

#define STB_IMAGE_IMPLEMENTATION
#define STB_DEFINE
#include "../extern/stb_image/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../extern/stb_image/stb_image_write.h"



struct ImageWrapper
{
    unsigned char * data;
    int width, height, channels;
    ImageWrapper(const std::string & path)
    {
        data = stbi_load(path.c_str(), &width, &height, &channels, 0);
        if(data == NULL)
        {
            std::cout << "Could not find image '" << path << "'" << std::endl;
            exit(1);
        }
    }
    
    ~ImageWrapper()
    {
         stbi_image_free(data);
    }

    const unsigned char *
    pixel_ptr(const size_t i, const size_t j) const
    {
        return data + ((j%height)*width + (i%width))*channels;

    }
    
    std::array<uint8_t, 4>
    operator()(const size_t i,
               const size_t j) const
    {
        const unsigned char * pix = data + ((j%height)*width + (i%width))*channels;
        if (channels < 3)
        {
            const auto [r,g,b] = grayscale_to_rgb(*pix);
            return {r,g,b,255};
        } else if (channels == 3)
        {
            return {pix[0], pix[1], pix[2], 255};
        }
        else
        {
            return {pix[0], pix[1], pix[2], pix[3]};
        }
    }

    void
    save(const std::string & path) const
    {
        stbi_write_png(path.c_str(),
                       width, height,
                       channels, data,
                       width * channels);
    }

    template<typename P>
    std::function<P(const std::uint32_t, const std::uint32_t)>
    pixels() const
    {
        
        // TEST IF sizeof(P) == img.channels!!!!!!
        assert(sizeof(P) == channels);
    
        return [&](const uint32_t i,
                   const uint32_t j)
        {   // pointer magic
            const unsigned char * pix_raw = this->pixel_ptr(j,i);
//                data + ((j%width)*height + (i%height))*channels;
            const P * pix_cast = reinterpret_cast<const P*>(pix_raw); 
            return *pix_cast;
        };
    }
};
template<typename P>
void
save_img(const std::string & path, const P * data,
         const size_t width, const size_t height,
         const size_t channels)
{
    stbi_write_png(path.c_str(),
                   width, height,
                   channels, data,
                   width * channels);
}
