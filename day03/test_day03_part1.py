# unittest

import unittest

from day3_part1 import myday3_part1

class TestDay3Part1(unittest.TestCase):

    def test_testdata(self):
        datafile = "test-data.txt"
        print("TEST datafile: %s" % datafile)
        power_consumption = myday3_part1(datafile)
        self.assertEqual(power_consumption, 198)

if __name__ == '__main__':
    unittest.main()


