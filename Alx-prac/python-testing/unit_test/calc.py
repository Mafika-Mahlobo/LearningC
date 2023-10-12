"""
These functions perform basic calculations
"""

def add(a, b):
	return a + b

def sub(a, b):
	return a - b

def mul(a, b):
	return a * b

def div(a, b):
	if b == 0:
		raise ValueError("Can't divide by 0")
	return a / b
