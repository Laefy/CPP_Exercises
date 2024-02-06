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
