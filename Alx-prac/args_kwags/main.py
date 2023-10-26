"""Practicig *args and **kwags in python"""

def take_args(full_name, *details, **more):

	count = 1
	
	print(f"Full name: {full_name}")
	print()
	for entry in details:
		print(f"entry {count} of personal details: {entry}")
		count += 1
	
	print()
	for k, v in more.items():
		print(f"{k} : {v}")
