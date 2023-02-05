cmake_minimum_required(VERSION 3.16)
project(CPP_Exercices)

add_subdirectory(extern/Catch2)
include(CTest)
include(Catch)

file(GLOB all_tests tests/Test-*.cpp)

foreach(test_file ${all_tests})

    get_filename_component(test_name ${test_file} NAME_WE)
    add_executable(${test_name}
        ${test_file}
        src/PC.cpp
        src/PC.h
        src/Pokeball.cpp
        src/Pokeball.h
        src/Pokemon.cpp
        src/Pokemon.h
        src/Trainer.cpp
        src/Trainer.h
    )

    target_include_directories(${test_name} PRIVATE src/)
    target_link_libraries(${test_name} PRIVATE Catch2::Catch2WithMain)

    target_compile_features(${test_name} PRIVATE cxx_std_17)
    target_compile_options(${test_name} PRIVATE
        -Wall
        -Wextra
        -Werror
        -Wno-uninitialized
    )

    add_custom_target(run-${test_name} COMMAND ./${test_name} DEPENDS ${test_name})
    catch_discover_tests(${test_name})

endforeach()
