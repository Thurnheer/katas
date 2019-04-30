#pragma once

#include <algorithm>
#include <iterator>
#include <numeric>
#include <vector>

#include <iostream>

namespace kata {

auto min = [](auto a, auto b) {
    return a < b ? a : b;
};

auto max = [](auto a, auto b) {
    return a > b ? a : b;
};

template<class InputItr, class Op>
auto adjacent_f(InputItr begin, InputItr end, Op op)
{
    std::vector<typename std::iterator_traits<InputItr>::value_type> result(begin, end);
    std::adjacent_difference(result.begin(), result.end(),
        result.begin(), op);
    return result;
}

template <typename T>
T calculate_max_profit(const std::vector<T>& stock_prices)
{
    std::vector<T> minValues(adjacent_f(stock_prices.begin(), stock_prices.end(), kata::min));
    std::vector<T> maxValues(adjacent_f(stock_prices.rbegin(), stock_prices.rend(), kata::max));

    return std::inner_product(maxValues.rbegin(), maxValues.rend(),
                minValues.begin(), 0, kata::max, std::minus<>());
}

} // namespace kata

