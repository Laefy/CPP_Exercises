cmake_minimum_required(VERSION 3.16)
project(CPP_Exercices)

file(GLOB tp_folders TP*)

foreach(tp ${tp_folders})
    add_subdirectory(${tp})
endforeach()
