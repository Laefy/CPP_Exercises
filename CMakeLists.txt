cmake_minimum_required(VERSION 3.18)
project(CPP_Exercices)

add_subdirectory(extern/Catch2)

if(MSVC)
    add_compile_options(/std:c++17 /W4 /WX)
else()
    add_compile_options(-std=c++17 -Wall -W -Werror -Wextra -Wfatal-errors -Wno-unused-variable)
endif()

set_property(GLOBAL PROPERTY CTEST_TARGETS_ADDED 1)

include(CTest)
include(Catch)

file(GLOB all_tests tests/test*)



foreach(test_fullpath ${all_tests})
    get_filename_component(test_basename ${test_fullpath} NAME_WE)

    # ${test_id} contains the part before the first `-`.
    string(REGEX REPLACE "-.*" "" test_id ${test_basename})
    # ${test_num} contains the test number.
    string(REGEX REPLACE "test" "" test_num ${test_id})
    # ${test_short_desc} contains the part after the first `-`.
    string(REGEX REPLACE "test[0-9]*-" "" test_short_desc ${test_basename})

    # ${exec_name} is the name of the built executable
    set(exec_name "${test_id}")
    add_executable(${exec_name} EXCLUDE_FROM_ALL 
        ${test_fullpath}
        src/ArrayNode.cpp
        src/InstanceCounter.cpp
        src/Leaf.cpp
        src/Node.cpp
        src/NodeKind.cpp
        src/IntLeaf.cpp
        src/ObjectNode.cpp
        src/StringLeaf.cpp
        # <-------------------------------------------------------------------- ADD FILES HERE
        )
    IF(${test_num} GREATER_EQUAL 20)
        target_sources(${exec_name} PRIVATE "src/JsonParser.cpp")
    ENDIF()

    target_link_libraries(${exec_name} PRIVATE Catch2::Catch2WithMain)

    # zrun-${exec_name} is a custom target that builds and runs ${exec_name}
    add_custom_target(zrun-${exec_name} 
        COMMAND ./${exec_name} 
        DEPENDS ${exec_name})
    add_test(
        NAME "${test_basename}" 
        COMMAND "${CMAKE_COMMAND}" --build ${CMAKE_BINARY_DIR} --target zrun-${exec_name})

endforeach()

add_custom_target(clean-tests COMMAND ${CMAKE_MAKE_PROGRAM} clean WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
#add_custom_target(run-tests COMMAND ${CMAKE_MAKE_PROGRAM} test WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})


add_executable(sandbox EXCLUDE_FROM_ALL 
    src/sandbox.cpp        
    src/ArrayNode.cpp
    src/InstanceCounter.cpp
    src/Node.cpp
    src/NodeKind.cpp
    src/IntLeaf.cpp
    src/Leaf.cpp
    src/ObjectNode.cpp
    src/StringLeaf.cpp
    # <-------------------------------------------------------------------- ADD FILES HERE
)

target_link_libraries(sandbox PRIVATE Catch2::Catch2WithMain)


# NE PAS MODIFIER CE FICHIER !
