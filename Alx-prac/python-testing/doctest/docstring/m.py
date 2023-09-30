"""
running doctest from docstring of script
"""

def add(a, b):
	
	"""
	test cases

	>>> add(1,2)
	3

	>>> add(5, 5)
	10

	"""

	return a + b

if __name__ == '__main__':
	import doctest
	doctest.testmod(verbose=True)
