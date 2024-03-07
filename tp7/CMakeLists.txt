cmake_minimum_required(VERSION 3.16)
project(TP7)

add_executable(tp7-ex2
    dungeon/Dungeon.cpp
    dungeon/Entity.hpp
    dungeon/Logger.hpp
    dungeon/Random.cpp
    dungeon/Random.hpp
)

target_compile_features(tp7-ex2 PRIVATE cxx_std_17)
target_compile_options(tp7-ex2 PRIVATE "-Wfatal-errors")

if(WIN32)
    target_compile_definitions(tp7-ex2 PRIVATE "WINDOWS")
endif()