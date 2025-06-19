cmake_minimum_required(VERSION 3.10)
project(LIST)

message("Project: ${PROJECT_NAME}")

option(BUILD_SHARED_LIBS "Build library" ON)

add_library(implementation implementation/list.cpp implementation/list.hpp)

target_include_directories(implementation PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/implementation)

add_executable(list main.cpp)
target_link_libraries(list implementation)