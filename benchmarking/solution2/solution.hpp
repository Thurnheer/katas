#pragma once

#include <algorithm>
#include <iterator>
#include <numeric>
#include <vector>
#include <tuple>

namespace kataSolution2 {

auto min = [](auto a, auto b) { return a < b ? a : b; }
auto max = [](auto a, auto b) { return a > b ? a : b; };

} // namespace kataSolution2

namespace kata {

template <typename T>
T calculate_max_profit(const std::vector<T>& stock_prices)
{
  return std::get<1>(std::accumulate(stock_prices.begin(),
                                     stock_prices.end(),
                                     std::make_tuple<T, T>(T{ std::numeric_limits<T>::max() }, T{ 0 }),
                                     [](std::tuple<T, T> acc, T value) {
                                       auto& [currentMinimum, difference] = acc;
                                       currentMinimum                     = kataSolution2::min(currentMinimum, value);
                                       difference = kataSolution2::max(difference, value - currentMinimum);
                                       return acc;
                                     }));
}

} // namespace kata
