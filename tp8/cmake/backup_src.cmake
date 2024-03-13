file(GLOB src_files ${SRC_PATH}/*)

execute_process(COMMAND "${CMAKE_COMMAND}" -E make_directory
    "${DST_PATH}"
)

foreach(file_path ${src_files})

    get_filename_component(file_name ${file_path} NAME)
    execute_process(COMMAND "${CMAKE_COMMAND}" -E copy_if_different
        "${file_path}"
        "${DST_PATH}/${file_name}"
    )

endforeach()
