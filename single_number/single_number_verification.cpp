#include "single_number.hpp"

#include <gtest/gtest.h>

namespace kata {


TEST(verify, function_should_find_return_valid_output_for_single_element)
{
  int expected_val = 42;

  std::vector<int> input{ expected_val};

  EXPECT_EQ(expected_val, find_single_number(input));
}


TEST(verify, function_should_find_expected_value_from_small_sorted_array)
{
  int expected_val = 12;

  std::vector<int> input{ expected_val, 2, 2, 2 };

  EXPECT_EQ(expected_val, find_single_number(input));
}

TEST(verify, function_should_find_expected_value_within_more_complecated_array)
{
  int expected_val = 1;

  std::vector<int> input{ 2, 5, -3, 2, expected_val, 2, 5, -3, 5, -3 };

  EXPECT_EQ(expected_val, find_single_number(input));
}

TEST(verify, function_should_find_expected_value_within_large_numbers)
{
  int expected_val = 25;

  std::vector<int> input{ std::numeric_limits<int>::max(),
                          2,
                          5,
                          -3,
                          2,
                          std::numeric_limits<int>::max() - 4,
                          expected_val,
                          2,
                          5,
                          std::numeric_limits<int>::max(),
                          -3,
                          std::numeric_limits<int>::max() - 4,
                          std::numeric_limits<int>::max(),
                          std::numeric_limits<int>::max() - 4,
                          5,
                          -3 };

  EXPECT_EQ(expected_val, find_single_number(input));
}

} // namespace kata
