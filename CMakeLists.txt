cmake_minimum_required(VERSION 3.16)
cmake_policy(SET CMP0110 NEW)
project(CPP_Exercices)

add_subdirectory(extern/Catch2)

include(Catch)
enable_testing()

file(
    GLOB
    common_sources

    lib/Consumable.hpp
    lib/Cupboard.hpp
    lib/Ingredient.hpp
    lib/Recipe.hpp
    lib/Unit.hpp

    src/Kitchen.cpp
    src/Kitchen.hpp

    # Si vous ajoutez de nouveaux fichiers, vous pouvez le faire ici...
)

file(GLOB all_tests tests/Tests-*)

foreach(test_path ${all_tests})
    get_filename_component(test_name ${test_path} NAME_WE)

    # ${test_id} contains the part before the first `-`.
    string(REGEX REPLACE "-.*" "" test_id ${test_name})
    # ${test_num} contains the test number.
    string(REGEX REPLACE "test" "" test_num ${test_id})
    # ${test_short_desc} contains the part after the first `-`.
    string(REGEX REPLACE "test[0-9]*-" "" test_short_desc ${test_name})

    add_executable(
        ${test_name} EXCLUDE_FROM_ALL 
        ${test_path}
        ${common_sources}
    )

    target_compile_features(${test_name} PRIVATE cxx_std_17)
    target_compile_options(${test_name} PRIVATE -Wall -W -Wextra -Wfatal-errors -Wno-unused-variable)
    target_link_libraries(${test_name} PRIVATE Catch2::Catch2WithMain)

    # zrun-${test_name} is a custom target that builds and runs ${test_name}
    add_custom_target(zrun-${test_name} 
        COMMAND ./${test_name} 
        DEPENDS ${test_name})

    add_test(
        NAME "${test_name}" 
        COMMAND "${CMAKE_COMMAND}" --build ${CMAKE_BINARY_DIR} --target zrun-${test_name})

endforeach()

add_executable(
    kitchen 
    src/Main.cpp
    ${common_sources}
)

set_target_properties(
    kitchen
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/kitchen"
)

target_compile_features(kitchen PRIVATE cxx_std_17)
target_compile_options(kitchen PRIVATE -Wall -W -Wextra -Wfatal-errors -Wno-unused-variable)
target_link_libraries(kitchen PRIVATE Catch2::Catch2)
