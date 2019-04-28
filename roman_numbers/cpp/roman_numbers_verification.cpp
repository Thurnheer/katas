#include "roman_numbers.hpp"
#include <gtest/gtest.h>

namespace rn {

TEST(roman_numbers, zero_should_convert_to_empty_string)
{
  EXPECT_EQ("", convert_to_roman(0));
}

TEST(roman_numbers, overflow_returns_empty_string)
{
  EXPECT_EQ("", convert_to_roman(3001));
}

TEST(roman_numbers, arabic_number_should_correctly_convert_to_roman)
{
  EXPECT_EQ("II", convert_to_roman(2));
  EXPECT_EQ("X", convert_to_roman(10));
  EXPECT_EQ("CCC", convert_to_roman(300));
  EXPECT_EQ("MMM", convert_to_roman(3000));
  EXPECT_EQ("MCCCXXI", convert_to_roman(1321));
  EXPECT_EQ("XCVIII", convert_to_roman(98));
  EXPECT_EQ("CDLIX", convert_to_roman(459));
  EXPECT_EQ("MCMXC", convert_to_roman(1990));
}

} // namespace rn
