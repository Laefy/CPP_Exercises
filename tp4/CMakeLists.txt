cmake_minimum_required(VERSION 3.16)
project(TP4)

file(GLOB exercice_folders "${CMAKE_CURRENT_SOURCE_DIR}/ex[0-9]*")
foreach(exercice_folder ${exercice_folders})

    get_filename_component(exercice_id ${exercice_folder} NAME_WE)
    file(GLOB_RECURSE exercice_src "${exercice_folder}/src/*")

    file(GLOB_RECURSE exercice_tests "${exercice_folder}/tests/*")
    foreach(exercice_test ${exercice_tests})

        get_filename_component(test_id ${exercice_test} NAME_WE)

        add_executable(${exercice_id}-${test_id}
            ${exercice_src}
            ${exercice_test}
        )

        set_property(TARGET ${exercice_id}-${test_id}
            PROPERTY sources_folder "${exercice_folder}/src"
        )

    endforeach()

endforeach()

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/configure_targets.cmake)

# file(GLOB src_ex0 "${CMAKE_CURRENT_SOURCE_DIR}/src/ex0/QCM.hpp")
# file(GLOB src_ex1 "${CMAKE_CURRENT_SOURCE_DIR}/lib/Logger.hpp")
# file(GLOB src_ex1_rect "${CMAKE_CURRENT_SOURCE_DIR}/src/ex1/Rectangle.*")
# file(GLOB src_ex1_inv "${CMAKE_CURRENT_SOURCE_DIR}/src/ex1/RectangleInverter.*")
# file(GLOB src_ex1_pol "${CMAKE_CURRENT_SOURCE_DIR}/src/ex1/Polygon.*")
# file(GLOB src_ex1_tri "${CMAKE_CURRENT_SOURCE_DIR}/src/ex1/Triangle.*")
# file(GLOB src_ex1_rg "${CMAKE_CURRENT_SOURCE_DIR}/src/ex1/PrintRange.*")
# file(GLOB src_ex1_frc "${CMAKE_CURRENT_SOURCE_DIR}/src/ex1/Fraction.*")
# file(GLOB src_ex2 "${CMAKE_CURRENT_SOURCE_DIR}/src/ex2/*")
# file(GLOB src_ex3 "${CMAKE_CURRENT_SOURCE_DIR}/lib/Fighter.hpp")
# file(GLOB src_ex3_fgt "${CMAKE_CURRENT_SOURCE_DIR}/src/ex3/Round.*")
# file(GLOB src_ex3_tmt "${CMAKE_CURRENT_SOURCE_DIR}/src/ex3/Tournament.*")

# set(src_test100 ${src_ex1_rect} ${src_ex1_pol})
# set(src_test101 ${src_ex1_rect} ${src_ex1_pol})
# set(src_test102 ${src_ex1_rect} ${src_ex1_pol})
# set(src_test103 ${src_ex1_rect} ${src_ex1_pol})
# set(src_test104 ${src_ex1_rect} ${src_ex1_pol})
# set(src_test105 ${src_ex1_rect} ${src_ex1_pol})
# set(src_test106 ${src_ex1_rect} ${src_ex1_pol})
# set(src_test107 ${src_ex1_rect} ${src_ex1_pol})
# set(src_test110 ${src_ex1_rect} ${src_ex1_pol})
# set(src_test111 ${src_ex1_rect} ${src_ex1_pol})
# set(src_test112 ${src_ex1_rect} ${src_ex1_pol})
# set(src_test113 ${src_ex1_rect} ${src_ex1_pol})
# set(src_test114 ${src_ex1_rect} ${src_ex1_pol})
# set(src_test120 ${src_ex1_rect} ${src_ex1_pol} ${src_ex1_inv})
# set(src_test121 ${src_ex1_rect} ${src_ex1_pol} ${src_ex1_inv})
# set(src_test130 ${src_ex1_rect} ${src_ex1_pol} ${src_ex1_tri})
# set(src_test131 ${src_ex1_rect} ${src_ex1_pol} ${src_ex1_tri})
# set(src_test132 ${src_ex1_pol})
# set(src_test133 ${src_ex1_rect} ${src_ex1_pol} ${src_ex1_tri})
# set(src_test134 ${src_ex1_pol} ${src_ex1_tri})
# set(src_test135 ${src_ex1_pol} ${src_ex1_tri})
# set(src_test140 ${src_ex1_rect} ${src_ex1_pol})
# set(src_test150 ${src_ex1_rg})
# set(src_test151 ${src_ex1_frc})
# set(src_test300 ${src_ex3_fgt})
# set(src_test301 ${src_ex3_fgt})
# set(src_test310 ${src_ex3_fgt} ${src_ex3_tmt})
# set(src_test311 ${src_ex3_fgt} ${src_ex3_tmt})
# set(src_test320 ${src_ex3_fgt} ${src_ex3_tmt})
# set(src_test321 ${src_ex3_fgt} ${src_ex3_tmt})
# set(src_test330 ${src_ex3_fgt} ${src_ex3_tmt})
# set(src_test331 ${src_ex3_fgt} ${src_ex3_tmt})

# set_property(GLOBAL PROPERTY CTEST_TARGETS_ADDED 1)

# include(CTest)
# include(Catch)

# add_executable(sandbox EXCLUDE_FROM_ALL src/sandbox.cpp ${lib_sources})

# file(GLOB all_exercices tests/ex*)

# foreach(exercice_fullpath ${all_exercices})
#     get_filename_component(exercice_basename ${exercice_fullpath} NAME_WE)

#     file(GLOB all_tests ${exercice_fullpath}/test*)

#     foreach(test_fullpath ${all_tests})
#         get_filename_component(test_basename ${test_fullpath} NAME_WE)

#         # ${test_id} contains the part before the first `-`.
#         string(REGEX REPLACE "-.*" "" test_id ${test_basename})
#         # ${test_num} contains the test number.
#         string(REGEX REPLACE "test" "" test_num ${test_id})
#         # ${test_short_desc} contains the part after the first `-`.
#         string(REGEX REPLACE "test[0-9]*-" "" test_short_desc ${test_basename})

#         # ${exec_name} is the name of the built executable
#         set(exec_name "${test_id}")

#         file(GLOB sources
#             ${src_${exercice_basename}}
#             ${src_${test_id}}
#         )

#         add_executable(
#             ${exec_name} EXCLUDE_FROM_ALL
#             ${test_fullpath}
#             ${sources}
#         )

#         target_link_libraries(${exec_name} PRIVATE Catch2::Catch2WithMain)
#         target_include_directories(
#             ${exec_name}
#             PRIVATE
#             "${CMAKE_CURRENT_SOURCE_DIR}/src/${exercice_basename}"
#             "${CMAKE_CURRENT_SOURCE_DIR}/lib"
#         )

#         set(test_name "${test_num}-${test_short_desc}")
#         set(test_target "run-and-save-${exec_name}")

#         add_custom_target(
#             ${test_target}
#             DEPENDS ${exec_name}
#             COMMAND ./${exec_name}
#         )

#         add_custom_command(
#             TARGET ${test_target}
#             POST_BUILD
#             COMMAND "${CMAKE_COMMAND}"
#                 -DDST_PATH="${CMAKE_CURRENT_SOURCE_DIR}/backup/${test_id}"
#                 -DSRC_PATH="${CMAKE_CURRENT_SOURCE_DIR}/src/${exercice_basename}"
#                 -P "${CMAKE_SOURCE_DIR}/backup_src.cmake"
#         )

#         add_test(
#             NAME "${test_name}" 
#             COMMAND "${CMAKE_COMMAND}" --build ${CMAKE_BINARY_DIR} --target ${test_target})
            
#         set_tests_properties("${test_name}" PROPERTIES TIMEOUT 300)
#         set_tests_properties("${test_name}" PROPERTIES FIXTURES_REQUIRED "${test_id}")

#     endforeach()
# endforeach()

# add_custom_target(clean-tests COMMAND ${CMAKE_MAKE_PROGRAM} clean WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
# #add_custom_target(run-tests COMMAND ${CMAKE_MAKE_PROGRAM} test WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

