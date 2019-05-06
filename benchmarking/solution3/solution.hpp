#pragma once

#include <numeric>
#include <algorithm>
#include <vector>

namespace kata {

/*

template <typename T>
T calculate_max_profit(const std::vector<T>& stock_prices)
{
T maxDifference     = 0;
T currentMinElement = std::numeric_limits<T>::max();

for(auto element : stock_prices)
{
  if(element < currentMinElement)
  {
    currentMinElement = element;
  }

  T diff = element - currentMinElement;
  if(diff > maxDifference)
    maxDifference = diff;
}

return maxDifference;
}
*/

template <typename T>
T calculate_max_profit(const std::vector<T>& stock_prices)
{
  T minimum{ std::numeric_limits<T>::max() };
  T max_profit{ 0 };

  for(auto element : stock_prices)
  {
    minimum    = std::min(minimum, element);
    max_profit = std::max(max_profit, element - minimum);
  }
  return max_profit;
}

} // namespace kata
