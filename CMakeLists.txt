cmake_minimum_required(VERSION 3.17)
project(Spicypp)

set(CMAKE_CXX_STANDARD 17)
include(GoogleTest)

if (MSVC)
    # warning level 4 and all warnings as errors
    add_compile_options(/W4 /WX)
else()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall -Wextra -pedantic-errors -Werror)
endif()


add_library(matrix STATIC src/Backend/Matrix.cpp)
add_executable(spicy src/SpicyPP.cpp)

target_link_libraries(spicy LINK_PUBLIC matrix)

add_executable(matrix_test src/Backend/Matrix_test.cpp)
gtest_discover_tests(matrix_test)
