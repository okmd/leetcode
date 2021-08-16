import unittest


def gcd_of(a, b):
    if a == 0:
        return b
    return gcd_of(b % a, a)


class TestCode(unittest.TestCase):
    def test_1(self):
        self.assertEqual(gcd_of(5, 6), 1)
        self.assertEqual(gcd_of(12, 6), 6)
        self.assertEqual(gcd_of(12, 26), 2)
        self.assertEqual(gcd_of(13, 6302948), 1)


if __name__ == "__main__":
    unittest.main()
