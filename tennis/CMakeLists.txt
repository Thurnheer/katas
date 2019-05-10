cmake_minimum_required(VERSION 3.10)

project(tennis)

enable_testing()

option(VERIFICATION OFF)
include(CTest)

include(${CMAKE_BINARY_DIR}/conan_paths.cmake)

find_package(trompeloeil)
find_package(Catch2 REQUIRED)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME}-uts
    tennis_verification.cpp)

target_link_libraries(${PROJECT_NAME}-uts 
    Catch2::Catch2)

add_test(NAME ${PROJECT_NAME}-uts COMMAND ${PROJECT_NAME}-uts)

if(VERIFICATION)

    add_test(NAME ${PROJECT_NAME}-verify COMMAND ${PROJECT_NAME}-verification)
endif()
