cmake_minimum_required(VERSION 3.10)
project(Spicypp)

set(CMAKE_CXX_STANDARD 17)
#include(GoogleTest)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


if (MSVC)
    # warning level 4 and all warnings as errors
    add_compile_options(/W4)
else()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall)
endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED PATHS /opt/qt/5.12.4/gcc_64/lib/cmake/)
add_library(matrix STATIC src/Backend/Matrix.cpp
                          src/Backend/Network.cpp
                          src/Backend/Resistor.cpp)
add_executable(spicy src/Frontend/SpicyPP.cpp
                     src/Frontend/MainWindow.cpp
                     src/Frontend/MainWindow.ui)

#if ("$CMAKE_BUILD_TYPE" STREQUAL "Debug")
  enable_testing()
  find_package(GTest REQUIRED)
  include(GoogleTest)
  add_executable(tests src/Backend/Matrix_test.cpp)
  target_link_libraries(tests matrix GTest::GTest GTest::Main)
  gtest_discover_tests(tests)
#endif()

target_link_libraries(spicy LINK_PUBLIC matrix Qt5::Widgets)

#add_executable(matrix_test src/Backend/Matrix_test.cpp)
#gtest_discover_tests(matrix_test) target_link_libraries(helloworld Qt5::Widgets)
