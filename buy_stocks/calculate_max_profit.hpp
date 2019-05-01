#pragma once

#include <algorithm>
#include <iterator>
#include <numeric>
#include <vector>
#include <tuple>

namespace kataSolution2 {

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
    std::vector<T> minValues(adjacent_f(stock_prices.begin(), stock_prices.end(), kataSolution2::min));
    std::vector<T> maxValues(adjacent_f(stock_prices.rbegin(), stock_prices.rend(), kataSolution2::max));

    return std::inner_product(maxValues.rbegin(), maxValues.rend(),
                minValues.begin(), 0, kataSolution2::max, std::minus<>());
}

} // namespace kata


namespace kata
{

/*auto minOfDifference = [](std::tuple<auto auto>, auto value) {*/
template<typename T>
std::tuple<T,T> minOfDifference(std::tuple<T, T> acc, T value) {
    auto& [currentMinimum, difference] = acc;
    currentMinimum = kataSolution2::min(currentMinimum, value);
    difference = value - currentMinimum;
    return acc;
}

template <typename T>
T calculate_max_profit(const std::vector<T>& stock_prices)
{
    return std::get<1>(std::accumulate(stock_prices.begin(), stock_prices.end(),
        std::make_tuple<T,T>(T{std::numeric_limits<T>::max()}, T{0}),
        [](std::tuple<T,T> acc, T value){
            auto& [currentMinimum, difference] = acc;
            currentMinimum = kataSolution2::min(currentMinimum, value);
            difference = kataSolution2::max(difference, value - currentMinimum);
            return acc;
        }));
}

} // namespace kata

