cmake_minimum_required(VERSION 3.16)
project(TP5)

add_executable(tp5-ex2
    2-ptr/main.cpp
    2-ptr/Object.hpp
)

target_compile_features(tp5-ex2 PRIVATE cxx_std_17)
target_compile_options(tp5-ex2 PRIVATE "-Wfatal-errors")

add_executable(tp5-ex3
    3-recipes/main.cpp
    3-recipes/Material.hpp
    3-recipes/ProgramData.cpp
    3-recipes/ProgramData.hpp
    3-recipes/Recipe.hpp
)

target_compile_features(tp5-ex3 PRIVATE cxx_std_17)
target_compile_options(tp5-ex3 PRIVATE "-Wfatal-errors")
