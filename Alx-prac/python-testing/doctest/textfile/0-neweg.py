"""
Using doctest from external text file (test.txt)
"""

def add(a, b):
	
	return a + b

import doctest
doctest.testfile('test.txt')
