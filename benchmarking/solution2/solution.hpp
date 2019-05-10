#pragma once

#include <algorithm>
#include <iterator>
#include <numeric>
#include <vector>
#include <tuple>

namespace kata {

template <typename T>
T calculate_max_profit(const std::vector<T>& stock_prices)
{
  return std::get<1>(
        std::accumulate(stock_prices.begin(), stock_prices.end(),
            std::make_tuple<T, T>(T{ std::numeric_limits<T>::max() }, T{ 0 }),
            [](std::tuple<T, T> acc, T value) {
                auto& [currentMinimum, difference] = acc;
                currentMinimum                     = std::min(currentMinimum, value);
                difference = std::max(difference, value - currentMinimum);
                return acc;
            }));
}

} // namespace kata
