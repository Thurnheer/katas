# Single number

## Installation/preparations
* Clone repository
* Go to `roman_numbers/cpp` to prepare C++ toolchain
    1. create build dir
        ```
        mkdir build && cd build
        ```
    2. add remote to conan for `google benchmark` library
        ```
        conan remote add conan-mpusz https://api.bintray.com/conan/mpusz/conan-mpusz
        ```
    3. get `gtest` and `google benchmark` libraries using conan
        ```
        conan install .. --build=missing
        ```
        you might need to give additional options (if build fails) eg.
        ```
        conan install .. -s compiler=gcc -s compiler.version=7.1 -s compiler.libcxx=libstdc++11 --build=missing
        ```
    4. prepare for build and build solution
        ```
        cmake .. && make
        ```
    5. run unittests
        ```
        ctest --verbose
        ```
## Exercise
1. You are given an array of integers, every element appears thrice except for one which occurs only once.
   Return element which appears only once.
    
    Assumptions:
    * Input array is valid (only 1 number appears once)
    
    Write C++ implementation in already prepared skeletons using TDD.
    
2. Verify your solution
    
    There are already prepared unittests checking the final solution. Please add  `-DVERIFICATION=ON` to cmake in 
    order to build verification tests. 
    
    run to see details of execution:
    ```
    ctest --verbose
    ```
3. Run your solution against benchmark using ```single_number-benchmark``` executable.
4. Improve your solution to match `O(n)` runtime complexity.
5. Improve your solution to have constant `O(1)` memory usage complexity. TIP: Bit Manipulation
