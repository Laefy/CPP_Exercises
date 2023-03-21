#pragma once

#include <array>
#include <stdint.h>
#include <cstddef>
#include <string>
#include <iostream>
#include <functional>

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
    
};


    
 
