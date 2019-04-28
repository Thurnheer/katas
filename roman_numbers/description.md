# Roman numerals

## Installation/preparations
* Clone repository
* Go to roman_numbers/cpp to prepare C++ toolchain
    1. create build dir
        ```
        mkdir build && cd build
        ```
    2. get `gtest` library using conan
        ```
        conan install .. --build=missing
        ```
        you might need to give additional options (if build fails) eg.
        ```
        conan install .. -s compiler=gcc -s compiler.version=7.1 -s compiler.libcxx=libstdc++11 --build=missing
        ```
    3. prepare for build and build solution
        ```
        cmake .. && make
        ```
    4. run unittests
        ```
        ctest --verbose
        ```
## Exercise
1. Got to cpp folder and write in TDD manner conversion function from arabic numerals to roman numerals using C++.
    
    Assumptions:
    * Function declaration looks as follows 
        ```
        std::string convert_to_roman(unsigned int arabic_number);
        ```
    * Valid roman numerals are in range `<1,3000>`
    * In case of invalid value return empty string
2. Verify your solution
    
    There are already prepared unittests checking the final solution. Please add  `-DVERIFICATION=ON` to cmake in 
    order to build verification tests. 
    
    run to see details of execution:
    ```
    ctest --verbose
    ```
3. Look at the problem from different perspective. Think of the problem not as a "conversion" issue but as 
"substitution" issue. Think about input not as an arabic numeral but string of given number of `I` letters.
4. Go to python folder and think of implementation of this kind of solution using python. Skeleton file 
`roman_numbers.py` is provided. You can use/modify 
already existing unit tests to check whether your solution work properly.

    Running python unittests:
    ```
    python -m unittest test_convert_to_roman
    ```

5. Using already developed C++ unit tests try to implement similar solution as in python.
6. Compare python/C++ solutions what are strengths and weaknesses of them.
