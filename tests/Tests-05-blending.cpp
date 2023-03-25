#include "../src/pixels.hpp"
#include "../src/image.hpp"

#include <catch2/catch_test_macros.hpp>

#include <iostream>
#include <type_traits>

TEST_CASE("We can add two images of the same size")
{
    Image<int, 2, 3> ima, imb;
    ima(0,0) = 21; ima(1,0) = 41 ;  imb(0,0) = 51 ; imb(1,0) = 91;
    ima(0,1) = 56; ima(1,1) = 123;  imb(0,1) = 41 ; imb(1,1) = 13;
    ima(0,2) = 13; ima(1,2) = 4  ;  imb(0,2) = 130; imb(1,2) = 123;

    const Image<int, 2, 3> imc = ima+imb;

    REQUIRE(imc(0,0) == 21+51);
    REQUIRE(imc(1,0) == 41+91);
    REQUIRE(imc(0,1) == 56+41);
    REQUIRE(imc(1,1) == 123+13);
    REQUIRE(imc(0,2) == 13+130);
    REQUIRE(imc(1,2) == 4+123);
    
}
TEST_CASE("Luma as transparency mask (RGB+Luma) => RGBA")
{
    const RGBA pix = RGB{1,3,4} + Luma{120};
    REQUIRE(pix.r == 1);
    REQUIRE(pix.g == 3);
    REQUIRE(pix.b == 4);
    REQUIRE(pix.a == 120);
}
TEST_CASE("Luma as transparency mask (RGBA+Luma) => RGBA")
{

    const RGBA pix = RGBA{1,3,4,200} + Luma{120};
    REQUIRE(pix.r == 1);
    REQUIRE(pix.g == 3);
    REQUIRE(pix.b == 4);
    REQUIRE(pix.a == (200*120)/255);
}
TEST_CASE("Luma as transparency mask (Luma+Luma) => RGBA")
{
    const RGBA pix = Luma{100} + Luma{120};
    const RGB rgb = from<RGB, Luma>(Luma{100});
    REQUIRE(pix.r == rgb.r);
    REQUIRE(pix.g == rgb.g);
    REQUIRE(pix.b == rgb.b);
    REQUIRE(pix.a == 120);
}

TEST_CASE("Blending (RGBA + RGBA) => RGBA")
{
    const RGBA a = RGBA{105, 37, 150, 34};
    const RGBA b = RGBA{5, 137, 54, 100};
    const RGBA pix = a + b;

    const std::array<uint8_t, 4> raw = lib::mix_color(a.r, a.g, a.b, a.a,
                                                 b.r, b.g, b.b, b.a);
    const RGBA truth = reinterpret_cast<const RGBA &>(raw);
    REQUIRE(truth.r == pix.r);
    REQUIRE(truth.g == pix.g);
    REQUIRE(truth.b == pix.b);
    REQUIRE(truth.a == pix.a);
}

TEST_CASE("Blending (RGB + RGBA) => RGBA")
{
    const RGBA a = RGBA{105, 37, 150, 34};
    const RGB  b = RGB {5, 137, 54};
    const RGBA pix = a + b;

    const std::array<uint8_t, 4> raw = lib::mix_color(a.r, a.g, a.b, a.a,
                                                 b.r, b.g, b.b, 255);
    const RGBA truth = reinterpret_cast<const RGBA &>(raw);
    REQUIRE(truth.r == pix.r);
    REQUIRE(truth.g == pix.g);
    REQUIRE(truth.b == pix.b);
    REQUIRE(truth.a == pix.a);
}

TEST_CASE("Blending (Luma + RGBA) => RGBA")
{
    const Luma a = Luma{109};
    const RGBA b = RGBA{105, 37, 150, 34};
    const RGBA pix = a + b;
    
    const RGBA c = from<RGBA, Luma>(a);
    const std::array<uint8_t, 4> raw = lib::mix_color(c.r, c.g, c.b, c.a,
                                                 b.r, b.g, b.b, b.a);
    const RGBA truth = reinterpret_cast<const RGBA &>(raw);
    REQUIRE(truth.r == pix.r);
    REQUIRE(truth.g == pix.g);
    REQUIRE(truth.b == pix.b);
    REQUIRE(truth.a == pix.a);
    
}


TEST_CASE("Blending (RGBA + RGB) => RGBA")
{
    const RGBA a = RGBA{105, 37, 150, 34};
    const RGB  b = RGB {5, 137, 54};
    const RGBA pix = a + b;

    const std::array<uint8_t, 4> raw = lib::mix_color(a.r, a.g, a.b, a.a,
                                                 b.r, b.g, b.b, 255);
    const RGBA truth = reinterpret_cast<const RGBA &>(raw);
    REQUIRE(truth.r == pix.r);
    REQUIRE(truth.g == pix.g);
    REQUIRE(truth.b == pix.b);
    REQUIRE(truth.a == pix.a);
}

TEST_CASE("Blending (RGB + RGB) => RGB")
{
    const RGB  a = RGB{105, 37, 150};
    const RGB  b = RGB{5, 137, 54};
    const RGB  pix = a + b;

    const std::array<uint8_t, 4> raw = lib::mix_color(a.r, a.g, a.b, 255,
                                                 b.r, b.g, b.b, 255);
    const RGBA truth = reinterpret_cast<const RGBA &>(raw);
    REQUIRE(truth.r == pix.r);
    REQUIRE(truth.g == pix.g);
    REQUIRE(truth.b == pix.b);
    REQUIRE(truth.a == 255);
}

TEST_CASE("Blending (Luma + RGB) => RGB")
{
    const Luma a = Luma{109};
    const RGB  b = RGB {105, 37, 150};
    const RGB  pix = a + b;
    
    const RGB  c = from<RGB, Luma>(a);
    const std::array<uint8_t, 4> raw = lib::mix_color(c.r, c.g, c.b, 255,
                                                 b.r, b.g, b.b, 255);
    const RGBA truth = reinterpret_cast<const RGBA &>(raw);
    REQUIRE(truth.r == pix.r);
    REQUIRE(truth.g == pix.g);
    REQUIRE(truth.b == pix.b);
    REQUIRE(truth.a == 255);
    
}

TEST_CASE("PHOTO COMPOSITING: RGBA+RGBA")
{
    {
        const Image<RGBA, 1012, 570> base("../images/photo_base.png");
        const Image<RGBA, 1012, 570> effect("../images/photo_dithering.png");
        const auto sum = base + effect;
        sum.save("images/compositing.png");
    }
    {
        const Image<RGB, 540, 788> base("../images/het_base.png");
        const Image<RGBA, 540, 788> effect("../images/het_rat.png");
        const Image<RGB , 540, 788> sum = base + effect;
        sum.save("images/het.png");
    }
}



TEST_CASE("PHOTO COMPOSITING: RGBA + LUMA")
{
    {
        const Image<RGB, 499, 499> base("../images/sonic.png");
        const Image<Luma, 499, 499> mask("../images/sonic_mask.png");
        const Image<RGBA, 499, 499> bg("../images/sonic_new_bg.png");
        const RGBA lol = from<RGBA, RGB>(base(10,10));
        std::cout << "aezaezaeza  "<< int(lol.a) << std::endl;
        std::cout << "aezaezaeza  "<< int(mask(10,10).gray) << std::endl;
        std::cout << "aezaezaeza  "<< int((lol+mask(10,10)).a) << std::endl; 
        const Image<RGBA, 499, 499> sum0 = base + mask;
        const Image<RGBA, 499, 499> sum = bg + sum0;
        sum.save("images/sonic_stars.png");
    }

}
