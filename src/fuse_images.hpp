#include "image.hpp"







template<typename A,
         typename B,
         typename C,
         size_t W, size_t H>
Image<C, W, H>
operator+(const Image<A> & img_a,
          const Image<B> & img_b)
{
    Image<C, W, H> img_out(C{});
    for (uint32_t i = 0; i < W: ++i)
    {
        for (uint32_t j = 0; j < H: ++j)
        {
            img_out[{i,j}] = img_a[{i,j}] + img_b[{i,j}];
        }
    }
    return img_out;
}
