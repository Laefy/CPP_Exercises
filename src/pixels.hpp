#pragma once

#include "../lib/lib.hpp"

#include <stdint.h>

struct RGBA
{
    uint8_t r,g,b,a;
};

struct RGB
{
    uint8_t r,g,b;
};

struct Luma
{
    uint8_t gray;
};


/*
template<typename Pix>
RGBA
to_rgba(const Pix & pix);

template<typename Pix>
Pix
from_rgba(const RGBA & pix);


template<>
RGBA
to_rgba(const )

*/

#include <iostream>

template<typename A, typename B>
A from(const B & stuff);

template<>
RGBA
from(const RGBA & stuff)
{
//    std::cout << "RGBA => RGBA" << std::endl;
    
    return stuff;
}

template<typename A, typename B>
B into(const A & stuff)
{
    return from<B,A>(stuff);
}

template<>
RGB from<RGB, RGBA>(const RGBA & pix)
{
    return {pix.r, pix.g, pix.b};
}
template<>
RGBA from<RGBA, RGB>(const RGB & pix)
{
    return {pix.r, pix.g, pix.b, 255};
}
template<>
Luma from<Luma, RGBA>(const RGBA & pix)
{
    return {rgb_to_grayscale(pix.r, pix.g, pix.b)};
}
template<>
RGBA from<RGBA, Luma>(const Luma & pix)
{
    const auto [r,g,b] = grayscale_to_rgb(pix.gray);
    return {r,g,b, 255};
}



template<typename A, typename B>
A from(const B & stuff)
{
    RGBA rgba = from<RGBA, B>(stuff);
    return from<A, RGBA>(rgba);
}


RGBA
mix_two_rgba(const RGBA & lhs,
             const RGBA & rhs)
{
    const auto & [r,g,b,a] = mix_color(lhs.r, lhs.g, lhs.b, lhs.a,
                                       rhs.r, rhs.g, rhs.b, rhs.a);
    return {r,g,b,a};
}
// RGB
// mix_two_rgb(const RGB & lhs,
//             const RGB & rhs)
// {
//     const auto & [r,g,b,a] = mix_color(rhs.r, rhs.g, rhs.b, 255,
//                                        lhs.r, lhs.g, lhs.b, 255);
//     return {r,g,b};
// }



// blending with at least one alpha channel (cast to rgba)
#define IMPL_ADD(A,B,C)                                    \
C operator+(const A & pix, const B & rhs)                  \
{                                                          \
   return from<C, RGBA>(mix_two_rgba(from<RGBA, A>(pix),   \
                                     from<RGBA, B>(rhs))); \
}

IMPL_ADD(RGBA, RGBA, RGBA);
IMPL_ADD(RGBA, RGB , RGBA);
IMPL_ADD(RGB , RGBA, RGB );
IMPL_ADD(Luma, RGBA, RGBA);
IMPL_ADD(Luma, RGB , RGB);
IMPL_ADD(RGB , RGB , RGB);

// mask operator
template<typename Pix>
RGBA
operator+(const Pix & pix,
          const Luma & mask)
{
//    std::cout << "aeazezae" << std::endl;
    RGBA rgba = from<RGBA, Pix>(pix);
    rgba.a = uint8_t((uint32_t(rgba.a)*uint32_t(mask.gray)/255));
    return rgba;
}



// RGB
// operator+(const RGB & pix,
//           const RGB & rhs)
// {
//     return from<RGB, RGBA>(from<RGBA, RGB>(pix) + from<RGBA, RGB>(rhs));
// }

// RGB
// operator+(const Luma & pix,
//           const RGB & rhs)
// {
//     return from<RGB, Luma>(pix) + rhs;
// }


/*
RGB
operator+(const RGB & pix,
          const Luma & rhs)
{
    return from<RGB, RGBA>(from<RGBA, RGB>(pix) + rhs);
}

*/
