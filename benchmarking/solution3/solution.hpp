#pragma once

#include <numeric>
#include <algorithm>
#include <vector>

namespace kata {

template <typename T>
T calculate_max_profit(const std::vector<T>& stock_prices)
{
  T minimum{ std::numeric_limits<T>::min() };
  T income{ 0 };

  for(auto element : stock_prices)
  {
    minimum = std::min(minimum, element);
    income  = std::max(income, element - minimum);
  }
  return income;
}

} // namespace kata
