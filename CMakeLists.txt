cmake_minimum_required(VERSION 3.16)
project(CPP_Exercices)

file(GLOB tp_folders ${CMAKE_CURRENT_SOURCE_DIR}/tp*)
foreach(tp_folder ${tp_folders})

if(EXISTS ${tp_folder}/CMakeLists.txt)
    add_subdirectory(${tp_folder})
endif()

endforeach()
