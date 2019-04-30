#include "calculate_max_profit.hpp"

#include <gtest/gtest.h>

namespace kata {

TEST(max_profit, should_be_0)
{
    std::vector<int> stock_prices{3, 2, 1};
    ASSERT_EQ(0, calculate_max_profit(stock_prices));
}

} // namespace kata
