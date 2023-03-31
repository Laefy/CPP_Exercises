cmake_minimum_required(VERSION 3.18)
project(2023-TPN1)

SET(sandbox_sources "")
foreach(file 
        src/sandbox.cpp
        # <------------------------------- AJOUTER VOS .cpp POUR LA SANDBOX ICI
        )
    list(APPEND sandbox_sources "${CMAKE_CURRENT_SOURCE_DIR}/${file}")
endforeach()

SET(ex1_sources "")
foreach(file 
        src/ex1.cpp
        # <----------------------------- AJOUTER VOS .cpp POUR l'EXERCICE 1 ICI
        )
    list(APPEND ex1_sources "${CMAKE_CURRENT_SOURCE_DIR}/${file}")
endforeach()


SET(ex2_sources "")
foreach(file 
        lib/InstanceCounter.cpp
        # <----------------------------- AJOUTER VOS .cpp POUR l'EXERCICE 2 ICI
        )
    list(APPEND ex2_sources "${CMAKE_CURRENT_SOURCE_DIR}/${file}")
endforeach()


SET(ex3_sources "${CMAKE_CURRENT_SOURCE_DIR}/lib/InstanceCounter.cpp")
foreach(file 
        # <----------------------------- AJOUTER VOS .cpp POUR l'EXERCICE 3 ICI
        )
    list(APPEND ex3_sources "${CMAKE_CURRENT_SOURCE_DIR}/${file}")
endforeach()









add_subdirectory(extern/Catch2)

if(MSVC)
    add_compile_options(/std:c++17 /W4 /WX)
else()
    add_compile_options(-std=c++17 -Wall -W -Wextra -Wfatal-errors -Wno-unused-variable)
endif()

set_property(GLOBAL PROPERTY CTEST_TARGETS_ADDED 1)

include(CTest)
include(Catch)

add_executable(sandbox EXCLUDE_FROM_ALL src/sandbox.cpp ${sandbox_sources})
target_link_libraries(sandbox PRIVATE Catch2::Catch2WithMain)

file(GLOB all_exercices tests/ex*)

foreach(exercice_fullpath ${all_exercices})
    get_filename_component(exercice_basename ${exercice_fullpath} NAME_WE)

    file(GLOB all_tests ${exercice_fullpath}/test*.cpp)

    foreach(test_fullpath ${all_tests})
        get_filename_component(test_basename ${test_fullpath} NAME_WE)
        EXECUTE_PROCESS(
            COMMAND grep -c "TEST_CASE" "${test_fullpath}"
            OUTPUT_VARIABLE testcase_count
        )

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
            ${${exercice_basename}_sources}
            )

        target_link_libraries(${exec_name} PRIVATE Catch2::Catch2WithMain)

        set(test_name "${test_num}-${test_short_desc}")

        IF("${testcase_count}" GREATER_EQUAL 2)
            add_test(
                NAME "${test_num}-${test_short_desc}--build" 
                COMMAND "${CMAKE_COMMAND}" --build ${CMAKE_BINARY_DIR} --target "${exec_name}")
            set_tests_properties("${test_num}-${test_short_desc}--build" PROPERTIES FIXTURES_SETUP "${test_id}")
            foreach(case_num RANGE 1 "${testcase_count}")
                math(EXPR case_let ${case_num}+96)
                string(ASCII ${case_let} case_let)
                set(subtest_name "${test_num}-${test_short_desc}--${case_let}")
                add_custom_target("zrun-${exec_name}${case_let}" 
                    COMMAND ./${exec_name} "${case_let}. \*"
                    DEPENDS ${exec_name})
                add_test(
                    NAME "${subtest_name}"
                    COMMAND "${CMAKE_COMMAND}" --build ${CMAKE_BINARY_DIR} --target "zrun-${exec_name}${case_let}")

                set_tests_properties("${subtest_name}" PROPERTIES TIMEOUT 60)
                set_tests_properties("${subtest_name}" PROPERTIES FIXTURES_REQUIRED "${test_id}")
            endforeach()
        ELSE()
            add_custom_target(zrun-${exec_name} 
                 COMMAND ./${exec_name} 
                 DEPENDS ${exec_name})  
            add_test(
                NAME "${test_name}" 
                COMMAND "${CMAKE_COMMAND}" --build ${CMAKE_BINARY_DIR} --target zrun-${exec_name})
        ENDIF()

    endforeach()
endforeach()
add_custom_target(clean-tests COMMAND ${CMAKE_MAKE_PROGRAM} clean WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
#add_custom_target(run-tests COMMAND ${CMAKE_MAKE_PROGRAM} test WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

