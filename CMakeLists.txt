cmake_minimum_required(VERSION 3.16)
project(CPP_Exercices)

add_executable(translator
    src/translator.cpp
)

target_compile_features(translator PRIVATE cxx_std_17)
target_compile_options(translator PRIVATE
	-Wall
	-Wextra
	-Werror
)
