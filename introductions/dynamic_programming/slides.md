# Dynamic Programming

---

What's that equal to? `1+1+1+1+1+1+1+1 =`

---

What about that? **`1+`** `1+1+1+1+1+1+1+1 =`

---

How'd you know it was nine so fast?

---

So you did not need to recount because you remembered there were eight! 
`Dynamic Programming` is just a fancy way to say `remembering stuff to save time later`

---

This conversation has the essence of dynamic programming.

The idea is very simple, If you have solved a problem with the given input, 
then save the result for future reference, so as to avoid solving the same problem
 again... shortly `Remember your Past`. If the given problem can be broken up in 
 to smaller sub-problems and these smaller subproblems are in turn divided in 
 to still-smaller ones, and in this process, if you observe some overlapping 
 subproblems, then its a big hint for DP. 

---

## Task: Calculate n-th fibonacci number

As everyone knows: `fib(n) = fib(n-1) + fib(n-2)` so we can provide a simple
implementation 

```cpp
unsigned int fib(unsigned int n)
{
    if(n <= 1) 
        return n;
    return fib(n - 1) + fib(n - 2)
}
```
So it works... but what is the complexity? 

`O(2^n)`

---

## What is the obvious problem?

---

## We recalculate again and again values...
What if we would remember them?

---
Ok. So, we try to save the value we calculate somewhere so that
 we don't compute it again. This is also called memoization.
```cpp
#include <array>

class fib
{
public:
    unsigned int calculate(unsigned int n)
    { 
        if(n <= 1) return n;
        if(memory[n] != 0) return memory[n];
        
        memory[n] = calculate(n - 1) + calculate(n - 2);
        return memory[n]; 
    }
private:
    std::array<unsigned int, 100> memory{0};
};
```
---

## So what changed? 

* `Space` complexity: We have an array of size n allocated for storing the results 
which has space complexity of `O(n)`. We also have the stack memory overhead of recursion 
which is also `O(n)`. 

    So, overall `space` complexity is `O(n)`.
---

* `Time` complexity: 
When `fib(n-1)` is called, it makes a call to `fib(n-2)`. So when the call 
comes back to the original call from `fib(n)`, `fib(n-2)` would already be 
calculated. Hence the call to `fib(n-2)` will be `O(1)`.
```text
Hence, T(n) = T(n - 1) + c where c is a constant. 
            = T(n - 2) + 2c
            = T(n - 3) + 3c
            = T(n - k) + kc
            = T(0) + n * c = 1 + n * c = O(n). 
```
Thanks to DP, we reduced a **exponential** problem to a **linear** problem!