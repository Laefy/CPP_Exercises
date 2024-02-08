add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/extern/Catch2-3.5.2)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/extern/Catch2-3.5.2/extras)

set_property(GLOBAL PROPERTY CTEST_TARGETS_ADDED 1)
include(CTest)

get_property(all_targets DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}" PROPERTY BUILDSYSTEM_TARGETS)
foreach(target ${all_targets})

    get_target_property(target_type ${target} TYPE)
    if (target_type STREQUAL "EXECUTABLE")

        target_link_libraries(${target} PRIVATE Catch2::Catch2WithMain)
        target_compile_features(${target} PRIVATE cxx_std_17)
        target_compile_options(${target} PRIVATE -Wall -W -Wextra -Wfatal-errors -Wno-unused-variable)

        set(test_target "run-and-save-${target}")

        add_custom_target(
            ${test_target}
            DEPENDS ${target}
            COMMAND $<TARGET_FILE:${target}>
        )

        add_custom_command(
            TARGET ${test_target}
            POST_BUILD
            COMMAND "${CMAKE_COMMAND}"
                -DDST_PATH="${CMAKE_CURRENT_SOURCE_DIR}/backup/${target}"
                -DSRC_PATH="$<TARGET_PROPERTY:${target},sources_folder>"
                -P "${CMAKE_CURRENT_SOURCE_DIR}/cmake/backup_src.cmake"
        )

        add_test(
            NAME "${target}" 
            COMMAND "${CMAKE_COMMAND}" --build ${CMAKE_BINARY_DIR} --target ${test_target}
        )

        set_tests_properties("${target}" PROPERTIES TIMEOUT 300)
        list(APPEND all_tests ${test_target})

    endif()

endforeach()
