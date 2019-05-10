#pragma once

#include <numeric>
#include <algorithm>
#include <vector>

namespace kata {

template <typename T>
T calculate_max_profit(const std::vector<T>& stock_prices)
{
  std::vector<T> min_values;
  std::vector<T> max_values;

  T min;
  for(typename std::vector<T>::const_iterator it = stock_prices.begin(); it != stock_prices.end(); ++it)
  {
    if (it == stock_prices.begin())
    {
      min = *it;
    }
    else
    {
      min = std::min(min, *it);
    }

    min_values.push_back(min);
  }

  T max;
  for(auto it = stock_prices.rbegin(); it != stock_prices.rend(); ++it)
  {
    if (it == stock_prices.rbegin())
    {
      max = *it;
    }
    else
    {
      max = std::max(max, *it);
    }

    max_values.push_back(max);
  }

  T diffMax = 0;
  for(auto i = 0, maxIndex = stock_prices.size(); i < maxIndex; ++i)
  {
    auto diff = max_values[maxIndex - i -1] - min_values[i];

    diffMax = std::max(diff, diffMax);
  }


  return diffMax;
}

} // namespace kata
