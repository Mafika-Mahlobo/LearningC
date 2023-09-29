"""
Example of using doctest to check interactive examples
in a docstring within the script
"""

def add(a, b):
    """
    doctest test cases for addition function.

    correct cases
    >>> add(5, 1) 
    6

    >>> add(1,2)
    3
    
    incorrect case
    >>> add(1,2)
    6

    """

    return a + b

if __name__ == '__main__':
	import doctest
	#doctest.testmod()
	#doctest.testmod(verbose=True)
