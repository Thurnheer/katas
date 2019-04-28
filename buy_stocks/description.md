# Calculate maximum profit

## Exercise
* We have an array for which the `i-th` element is the price 
of a given stock on day `i`.
   
   We can complete at most one transaction (buy and sell share of the stock), 
   design an algorithm to find the maximum profit.
   
```text
Having array:
[1, 2]
our maximum profit is to buy at day 1 and sell at the day 2 with "1" profit.
```

```text
[3, 1, 2, 6]
our maximum profit is "5" buying at day 2 and selling at the last day
```

* Solve the problem in TDD manner using `googletest` for function declaration:
```cpp
template<typename T>
T calculate_max_profit(const std::vector<T>&);
```
* Think of a way to refactor the tests to have ValueParametrized tests - refer to 
[this](https://github.com/google/googletest/blob/master/googletest/docs/advanced.md)
* Type parametrized tests?
* Look at the problem from different perspective [see short introduction to DP](../introductions/dynamic_programming/slides.md)
* Implement the solution using DP. What are the `time` and `space` complexities?
* Benchmark introduction - to compare the values