cmake_minimum_required(VERSION 3.10)
project(benchmark-test)

include(${CMAKE_BINARY_DIR}/conan_paths.cmake)
find_package(benchmark CONFIG REQUIRED)
find_package(GTest REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(solution1)
add_subdirectory(solution2)
add_subdirectory(solution3)
add_subdirectory(solution4)

add_executable(${PROJECT_NAME}-solution1 benchmark.cpp)
target_link_libraries(${PROJECT_NAME}-solution1 PRIVATE buy_stock_1 benchmark::benchmark)

add_executable(${PROJECT_NAME}-solution2 benchmark.cpp)
target_link_libraries(${PROJECT_NAME}-solution2 PRIVATE buy_stock_2 benchmark::benchmark)

add_executable(${PROJECT_NAME}-solution3 benchmark.cpp)
target_link_libraries(${PROJECT_NAME}-solution3 PRIVATE buy_stock_3 benchmark::benchmark)

add_executable(${PROJECT_NAME}-solution4 benchmark.cpp)
target_link_libraries(${PROJECT_NAME}-solution4 PRIVATE buy_stock_4 benchmark::benchmark)
