class Employee:
	def __init__(self, name, lname, pay):
		self.name = name
		self.lname = lname
		self.pay = pay

	def fullname(self):
		print(f"{self.name} {self.lname}")

emp1 = Employee('John', 'Doe', 70000)

emp1.fullname()
Employee.fullname(emp1)
# these two lines are similar
