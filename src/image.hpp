#pragma once

#include "pixels.hpp"

#include "../lib/image_io.hpp"

#include <cstddef>

template<typename P, size_t W, size_t H>
struct Image
{
    std::array<std::array<P, W>, H> _pixels;
    
    Image(const P & base_pixel)
    {
        for (auto & col: _pixels)
        {
            for (auto & pix: col)
            {
                pix = base_pixel;
            }
        }
    }
    Image() = default;

    P &
    operator()(const size_t i, const size_t j)
    {
        return _pixels[j][i];
    }
    const P &
    operator()(const size_t i, const size_t j) const
    {
        return _pixels[j][i];
    }


    Image<P, W, H>(const std::function<P(const size_t i, const size_t j)> & functor)
    {
        for (uint32_t i = 0; i < W; ++i)
        {
            for (uint32_t j = 0; j < H; ++j)
            {
                (*this)(i,j) = functor(i,j);
            }
        }
        
    }
    // à donner aux élèves
    Image<P, W, H>(const std::string & path)
    {
        int w, h, c;
        const uint8_t * data = stbi_load(path.c_str(),
                                         &w, &h, &c, 0);
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
                    (*this)(i,j) = *reinterpret_cast<const P *>(pixel_ptr);
                }
            }
        }
    }
    
    void
    save(const std::string & path) const
    {
        const auto data = reinterpret_cast<const uint8_t *>(this);
        stbi_write_png(path.c_str(), W, H, sizeof(P), data, W*sizeof(P));
    }
        

};


template<const size_t W, const size_t H,
         typename A, typename B>
Image<A, W, H>
operator+(const Image<A, W, H> & lhs,
          const Image<B, W, H> & rhs)
{
    Image<A, W, H> out{};
    for (uint32_t i = 0; i < W; ++i)
    {
        for (uint32_t j = 0; j < H; ++j)
        {
            out(i,j) = lhs(i,j) + rhs(i,j);
        }
    }
    return out;
}

template<size_t W, size_t H, typename A>
Image<RGBA, W, H>
operator+(const Image<A   , W, H> & lhs,
          const Image<Luma, W, H> & rhs)
{
    Image<RGBA, W, H> out{};
    for (uint32_t i = 0; i < W; ++i)
    {
        for (uint32_t j = 0; j < H; ++j)
        {
            out(i,j) = lhs(i,j) + rhs(i,j);
        }
    }
    return out;
}

