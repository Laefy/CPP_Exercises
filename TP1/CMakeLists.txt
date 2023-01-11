add_executable(
    hello-world
    helloworld.cpp
)

target_compile_features(hello-world PUBLIC cxx_std_17)