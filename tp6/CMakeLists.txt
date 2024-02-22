cmake_minimum_required(VERSION 3.16)
project(TP6)

add_executable(tp6-ex1
    1-recipes/main.cpp
    1-recipes/Material.hpp
    1-recipes/ProgramData.cpp
    1-recipes/ProgramData.hpp
    1-recipes/Recipe.hpp
)

target_compile_features(tp6-ex1 PRIVATE cxx_std_17)
target_compile_options(tp6-ex1 PRIVATE "-Wfatal-errors")
