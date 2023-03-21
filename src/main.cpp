
#include "../lib/image_io.hpp"


#include <iostream>



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
    
    
    std::cout << "oaawo" << std::endl;
    return 0;
}

