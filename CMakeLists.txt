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

    add_executable(
        ${test_name} EXCLUDE_FROM_ALL 
        ${test_path}
        ${common_sources}
    )

    set_target_properties(
        ${test_name}
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/tests"
    )

    target_compile_features(${test_name} PRIVATE cxx_std_17)
    target_compile_options(${test_name} PRIVATE -Wall -W -Wextra -Wfatal-errors -Wno-unused-variable)
    target_link_libraries(${test_name} PRIVATE Catch2::Catch2WithMain)

    add_test(
        NAME "BUILD-${test_name}"
        COMMAND "${CMAKE_COMMAND}" --build ${CMAKE_BINARY_DIR} --target "${test_name}")

    string(REGEX REPLACE "Tests-" "" test_desc ${test_name})

    catch_discover_tests(
        ${test_name}
        TEST_PREFIX "TEST-${test_desc}_"
    )

    add_custom_target(
        run-${test_desc}
        DEPENDS ${test_name}
        COMMAND ${CMAKE_CTEST_COMMAND} -R "^TEST-${test_desc}_.*" -j 10
    )

endforeach()

add_custom_target(
    clean-tests
    COMMAND ${CMAKE_COMMAND} -E rm -rf "${CMAKE_CURRENT_BINARY_DIR}/tests"
    COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_CURRENT_BINARY_DIR}/tests"
)

add_custom_target(
    build-tests
    COMMAND ${CMAKE_CTEST_COMMAND} -R "^BUILD-.*"
    DEPENDS clean-tests
)

add_custom_target(
    run-tests
    COMMAND ${CMAKE_CTEST_COMMAND} -R "^TEST-.*" -j 10
)

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
