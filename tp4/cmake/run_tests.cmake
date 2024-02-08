separate_arguments(TARGETS)

set(tests_count 0)
set(failures_count 0)

option(QUIET "Whether the errors of the tests are output" OFF)

foreach(target ${TARGETS})

    if(FILTER)

        if(NOT target MATCHES "${FILTER}")
            continue()
        endif()

    endif()

    math(EXPR tests_count "${tests_count}+1")

    execute_process(COMMAND 
        ${CMAKE_COMMAND} -E env CLICOLOR_FORCE=1
        ${CMAKE_COMMAND} -E cmake_echo_color --magenta --bold "${target}..."
    )

    execute_process(
        COMMAND "${CMAKE_COMMAND}" --build "${BUILD_DIR}" --target "${target}"
        OUTPUT_VARIABLE output
        ERROR_VARIABLE output
        RESULT_VARIABLE result
    )

    if(${result} EQUAL 0)

        execute_process(COMMAND 
            ${CMAKE_COMMAND} -E env CLICOLOR_FORCE=1
            ${CMAKE_COMMAND} -E cmake_echo_color --green --bold "=> SUCCESS"
        )

        if(NOT ${QUIET})
            message("")
        endif()

    else()

        execute_process(COMMAND 
            ${CMAKE_COMMAND} -E env CLICOLOR_FORCE=1
            ${CMAKE_COMMAND} -E cmake_echo_color --red --bold "=> FAILURE"
        )

        if(NOT ${QUIET})
            if(output)
                message(${output})
            endif()
        endif()

        math(EXPR failures_count "${failures_count}+1")

    endif()

endforeach()

if(${failures_count} EQUAL 0)

    execute_process(COMMAND 
        ${CMAKE_COMMAND} -E env CLICOLOR_FORCE=1
        ${CMAKE_COMMAND} -E cmake_echo_color --green --bold "======================\nALL ${tests_count} TESTS HAVE PASSED"
    )

else()

    execute_process(COMMAND 
        ${CMAKE_COMMAND} -E env CLICOLOR_FORCE=1
        ${CMAKE_COMMAND} -E cmake_echo_color --red --bold "===================================\n${failures_count} TESTS OUT OF ${tests_count} HAVE FAILED"
    )

endif()

