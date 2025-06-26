cmake_minimum_required(VERSION 3.10)
project(LIST)

message(STATUS "Project: ${PROJECT_NAME}")

option(BUILD_SHARED_LIBS "Build shared libraries" ON)

add_library(implementation implementation/list.cpp)

target_include_directories(implementation PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/implementation
)

include(FetchContent)

set(BUILD_GTEST ON)
set(INSTALL_GTEST OFF)
set(BUILD_SHARED_LIBS OFF)
set(gtest_force_shared_crt OFF)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(tests tests/test_list.cpp)

target_link_libraries(tests
    implementation
    gtest
    gtest_main
)

include(GoogleTest)
gtest_discover_tests(tests) 


add_executable(list main.cpp)

target_link_libraries(list implementation)
