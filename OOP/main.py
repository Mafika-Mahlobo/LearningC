class Employee:

	num_of_empl = 0 # class var. shoud be the same for every instance. use it with class name.
	raise_amount = 1.05 # instance class. can be the same or different betweeen instaces.
	
	def __init__(self, name, lname, pay):
		self.name = name
		self.lname = lname
		self.pay = pay

		# using class var
		Employee.num_of_empl += 1

	def fullname(self):
		print(f"{self.name} {self.lname}")

	# using instance var
	def apply_raise(self):
		self.pay = self.pay * self.raise_amount

print(f"Number of emplyees: {Employee.num_of_empl}")
emp1 = Employee('John', 'Doe', 7000)
emp2 = Employee('Peter', 'Smith', 7000)

# these line do the same thing
emp1.fullname()
Employee.fullname(emp1)
print()

print(f"Number of employees (employee 1): {emp1.num_of_empl}")
print(f"Number of employees (employee 2): {emp2.num_of_empl}")
print(f"Number of employees: {Employee.num_of_empl}")
print()

emp2.apply_raise()
print(emp2.pay)

emp1.raise_amount = 1.04
emp1.apply_raise()
print(emp1.pay)
