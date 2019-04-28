from unittest import TestCase

from roman_numbers import convert_to_roman


class TestConvertToRoman(TestCase):

    def test_zero_should_convert_to_empty_string(self):
        self.assertEqual('', convert_to_roman(0))

    def test_overflow_numeral_should_convert_to_empty_string(self):
        self.assertEqual('', convert_to_roman(3001))

    def test_conversion_between_roman_and_arabic(self):
        self.assertEqual('II', convert_to_roman(2))
        self.assertEqual('X', convert_to_roman(10))
        self.assertEqual('CCC', convert_to_roman(300))
        self.assertEqual('MMM', convert_to_roman(3000))
        self.assertEqual('MCCCXXI', convert_to_roman(1321))
        self.assertEqual('XCVIII', convert_to_roman(98))
        self.assertEqual('CDLIX', convert_to_roman(459))
        self.assertEqual('MCMXC', convert_to_roman(1990))
        self.assertEqual('MMXVIII', convert_to_roman(2018))
