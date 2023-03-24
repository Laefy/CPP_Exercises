
#include "../lib/image_io.hpp"

#include "image.hpp"
#include <iostream>


#include <complex>
int
main()
{
    const ImageWrapper img("images/test_image.png");
    for (size_t j = 0; j < 8; ++j)
    {
        for (size_t i = 0; i < 8; ++i)
        {
            const auto [r,g,b,a] = img(i,j);
            std::cout << (r!=0) << " ";
        }
        std::cout << std::endl;
    }
    img.save("images/huehuehuehu.png");

    const auto lol = img.pixels<RGBA>();
    
    std::cout << std::endl;
    Image<RGBA, 8, 8> img2(lol);
    
    for (size_t j = 0; j < 8; ++j)
    {
        for (size_t i = 0; i < 8; ++i)
        {
            const auto [r,g,b,a] = img2(i,j);
            std::cout << (r!=0) << " ";
        }
        std::cout << std::endl;
    }
    img2(1,1) = {255,0,0,255};
    img2(1,3) = {255,0,0,255};
    img2(1,4) = {255,0,0,255};
    img2(1,5) = {255,0,0,255}; 
    {
        
            
    }
    {
        const size_t WIDTH = 13;
        const size_t HEIGHT = 7;
        const auto foo = [](const size_t i, const size_t j)
        {
            if (!(i == 0 || j == 0 || i+1 == WIDTH || j+1 == HEIGHT))
//            if (((i%7+j*j) ^ 107) % 3)
            {
                return 0;
            }
            else
            {
                return 255;
            }
        };
        const Image<uint8_t, WIDTH, HEIGHT> img(foo);
        img.save("images/truc.png");

        for (size_t j = 0; j < HEIGHT; ++j)
        {
            for (size_t i = 0; i < WIDTH; ++i)
            {
                std::cout << ((img(i,j) == 0)?' ':'o') << " ";
            }
            std::cout << std::endl;

        }
    }
    std::cout << "oaawo" << std::endl;
    return 0;
}

