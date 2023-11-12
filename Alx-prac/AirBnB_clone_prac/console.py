#!/usr/bin/python3

"""
Interpreter
"""

import cmd

class HBNBCommand(cmd.Cmd):

	"""Contains the entry point of the command interpreter."""

	promt = "(hbnb)"

	def do_quit(self, arg):
		"""Quit command to exit the program"""

		return True

	def do_EOF(self, arg):
		"""Quit command to exit the program"""

		print("")
		return True

	def emptyline(self):
		"""DO nothing"""

		pass

if __name__ == '__main__':
	prompt = HBNBCommand()
	prompt.cmdloop()


