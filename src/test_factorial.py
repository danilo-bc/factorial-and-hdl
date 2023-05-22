import unittest


def factorial(n):
    if n < 0:
        raise ValueError("Factorial is not defined for negative numbers.")
    elif n == 0 or n == 1:
        return 1
    else:
        result = 1
        for i in range(2, n + 1):
            result *= i
        return result


class TestFactorial(unittest.TestCase):
    def test_factorial_of_zero(self):
        self.assertEqual(factorial(0), 1)

    def test_factorial_of_one(self):
        self.assertEqual(factorial(1), 1)

    def test_factorial_of_positive_number(self):
        self.assertEqual(factorial(5), 120)
        self.assertEqual(factorial(10), 3628800)
        self.assertEqual(factorial(15), 1307674368000)

    def test_factorial_of_negative_number(self):
        with self.assertRaises(ValueError):
            factorial(-5)


if __name__ == "__main__":
    unittest.main()
