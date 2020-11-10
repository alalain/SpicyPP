cmake_minimum_required(VERSION 3.10)
project(Spicypp)

set(CMAKE_CXX_STANDARD 17)
#include(GoogleTest)
#include(QT)

if (MSVC)
    # warning level 4 and all warnings as errors
    add_compile_options(/W4)
else()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall)
endif()


add_library(matrix STATIC src/Backend/Matrix.cpp)
add_executable(spicy src/SpicyPP.cpp)

target_link_libraries(spicy LINK_PUBLIC matrix)

#gtest_discover_tests(matrix_test)
