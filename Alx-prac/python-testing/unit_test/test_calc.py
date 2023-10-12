import unittest
import calc

class Calc_test(unittest.TestCase):
	
	def test_add(self):
		self.assertEqual(calc.add(1, 2), 3)
		self.assertEqual(calc.add(-1, -1), -2)
		
	def test_subtract(self):
		self.assertEqual(calc.sub(4, 2), 2)
		self.assertEqual(calc.sub(-3, 3), -6)

	def test_multiply(self):
		self.assertEqual(calc.mul(2, 2), 4)
		self.assertEqual(calc.mul(4, 0), 0)

	def test_div(self):
		self.assertEqual(calc.div(4, 2), 2)
		self.assertRaises(ValueError, calc.div, 2, 0)

		# using context manager
		#with self.assertRaises(ValueError):
		#	calc.div(1, 0)

if __name__ == '__main__':
	unittest.main()
