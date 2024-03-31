#pragma once

#include "../lib/image_lib.hpp"

#include <cstdint>

struct RGBA
{
    uint8_t r = 0;
    uint8_t g = 0;
    uint8_t b = 0;
    uint8_t a = 0;
};

struct RGB
{
    uint8_t r = 0;
    uint8_t g = 0;
    uint8_t b = 0;
};

struct Luma
{
    uint8_t l = 0;
};

template <typename To, typename From>
To convert(const From& stuff);

template <>
RGBA convert<RGBA, RGBA>(const RGBA& stuff)
{
    return stuff;
}

template <>
RGB convert<RGB, RGB>(const RGB& stuff)
{
    return stuff;
}

template <>
Luma convert<Luma, Luma>(const Luma& stuff)
{
    return stuff;
}

template <>
RGB convert<RGB, RGBA>(const RGBA& stuff)
{
    return RGB { stuff.r, stuff.g, stuff.b };
}

template <>
RGBA convert<RGBA, RGB>(const RGB& stuff)
{
    return RGBA { stuff.r, stuff.g, stuff.b, 255 };
}

template <>
Luma convert<Luma, RGB>(const RGB& stuff)
{
    return Luma { image_lib::rgb_to_grayscale(stuff.r, stuff.g, stuff.b) };
}

template <>
RGB convert<RGB, Luma>(const Luma& stuff)
{
    auto [r, g, b] = image_lib::grayscale_to_rgb(stuff.l);
    return RGB { r, g, b };
}
template <>
Luma convert<Luma, RGBA>(const RGBA& stuff)
{
    return convert<Luma>(convert<RGB>(stuff));
}

template <>
RGBA convert<RGBA, Luma>(const Luma& stuff)
{
    return convert<RGBA>(convert<RGB>(stuff));
}

inline RGBA operator+(const RGBA& lhs, const RGBA& rhs)
{
    auto [r, g, b, a] = image_lib::mix_color(lhs.r, lhs.g, lhs.b, lhs.a, rhs.r, rhs.g, rhs.b, rhs.a);
    return RGBA { r, g, b, a };
}

inline RGB operator+(const RGB& lhs, const RGBA& rhs)
{
    return convert<RGB>(convert<RGBA>(lhs) + rhs);
}

inline RGB operator+(const Luma& lhs, const RGBA& rhs)
{
    return convert<RGB>(convert<RGBA>(lhs) + rhs);
}

inline RGBA operator+(const RGBA& lhs, const RGB& rhs)
{
    return lhs + convert<RGBA>(rhs);
}

inline RGB operator+(const RGB& lhs, const RGB& rhs)
{
    return lhs + convert<RGBA>(rhs);
}

inline RGB operator+(const Luma& lhs, const RGB& rhs)
{
    return lhs + convert<RGBA>(rhs);
}

template <typename P>
RGBA operator+(const P& lhs, const Luma& mask)
{
    auto result = convert<RGBA>(lhs);
    result.a = (result.a * mask.l) / 255;
    return result;
}
