class User:
	def __init__(self, name, surname, balance):
		self.name = name
		self.surname = surname
		self.email = name.lower()+'@mycompany.com'
		self.balance = balance


def print_info(user=None):
	print(f"First Name: {user.name}\nLast Name: {user.surname}\nEmail Address: {user.email}\nBalance: {user.balance}")
	print()

def capture():
	pin = 1234
	name = input("Welcome!\nEnter your name: ")
	surname = input("Enter your last name: ")
	p = int(input("Enter pin: "))
	if p == pin:
		amount = input("Enter deposit amout: ")
	else:
		print("Sorry, could not deposit!")
		return 1

	return User(name, surname, amount)

while (1):
	count = 0
	prompt = input("Do you want to deposit?: (Y/N)")
	if prompt.lower() == 'y':
		instance  = "user"+str(count)
		instance = capture()
		print()
		print_info(instance)
		count += 1
	else:
		break

