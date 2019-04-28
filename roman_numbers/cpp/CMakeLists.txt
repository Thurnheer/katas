cmake_minimum_required(VERSION 3.10)

project(roman_numbers)

option(VERIFICATION OFF)
include(CTest)

include(${CMAKE_BINARY_DIR}/conan_paths.cmake)

find_package(GTest REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME}
        roman_numbers.cpp
        roman_numbers_tests.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE GTest::Main)

add_test(NAME ${PROJECT_NAME}-uts COMMAND ${PROJECT_NAME})

if(VERIFICATION)
    add_executable(${PROJECT_NAME}-verification
            roman_numbers.cpp
            roman_numbers_verification.cpp)

    target_link_libraries(${PROJECT_NAME}-verification PRIVATE GTest::Main)

    add_test(NAME ${PROJECT_NAME}-verify COMMAND ${PROJECT_NAME}-verification)
endif()
