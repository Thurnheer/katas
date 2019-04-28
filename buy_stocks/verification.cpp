#include "calculate_max_profit.hpp"

#include <gtest/gtest.h>

namespace kata {

TEST(verify, should_return_0_on_empty_input_or_only_single_day_in_array)
{
  std::vector<float> stock_prices{};
  EXPECT_EQ(0, calculate_max_profit(stock_prices));

  stock_prices.push_back(1);
  EXPECT_EQ(0, calculate_max_profit(stock_prices));
}

TEST(verify, should_count_correctly_values_depending_on_day)
{
  std::vector<double> stock_prices{ 4, 10, 2, 9, 1 };
  EXPECT_EQ(7, calculate_max_profit(stock_prices));
}

TEST(verify, should_be_able_to_correctly_handle_unsigned_ints)
{
  std::vector<unsigned int> stock_prices{ 4, 10, 2, 9, 1 };
  EXPECT_EQ(7, calculate_max_profit(stock_prices));
}

TEST(verify, should_return_0_when_there_is_no_profit)
{
  std::vector<int> stock_prices{ 5, 4, 3, 2, 1 };
  EXPECT_EQ(0, calculate_max_profit(stock_prices));
}

} // namespace kata
