# Benchmarking

## Exercise
We want to have a small introduction to [google benchmark](https://github.com/google/benchmark#passing-arguments).

The idea is to create a benchmark comparison for solutions to previous exercise.

Goal:
* Create new benchmark fixture for `ints`
* Have a fixed random seed for uniform distribution for input data `[1, 100]`
* Use benchmark to provide us asymptotic complexity and deviation
* run tests for range `[1, 32768]` with size multiplication `2`
* Run and check the results
* Try out additional tools from benchmark `compare.py` to see how it can provide results
* Think on a way to extend the tests for other values than `ints`

Side goals:
* `.clang-format` - what it actually is?
* We want to have the solution refactored until we are satisfied with the code quality.
