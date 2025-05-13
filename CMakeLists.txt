cmake_minimum_required(VERSION 3.22.1)

project(sample_c CXX)

option(SOME_FEATURE "Enable something" OFF)

include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB SHARED_SOURCE
    ${PROJECT_SOURCE_DIR}/src/*.cpp)

add_executable(my_program ${SHARED_SOURCE} my_program/main.cpp)

if(SOME_FEATURE)
    target_compile_definitions(my_program PRIVATE SOME_FEATURE)
endif()