cmake_minimum_required(VERSION 3.16)
project(hrsoft)

add_executable(hrsoft-tests
    HRSoftTests.cpp
    HRSoft/HRSoftSystem.hpp
    HRSoft/Department.hpp
    HRSoft/Employee.hpp
)

target_compile_features(hrsoft-tests PRIVATE cxx_std_17)

add_executable(hrsoft
    HRSoftMain.cpp
    HRSoft/HRSoftSystem.hpp
    HRSoft/Department.hpp
    HRSoft/Employee.hpp
)

target_compile_features(hrsoft PRIVATE cxx_std_17)
