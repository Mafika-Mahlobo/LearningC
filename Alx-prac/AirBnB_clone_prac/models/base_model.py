#!/usr/bin/python3

"""Defines a base class with all common attributes/methods"""

from datetime import datetime
import uuid


class BaseModel:

	"""Defines all common attributes/methods for other classes."""

	updated_at

	def __init__(self):
		"""Initializes attributes when instance is created."""
		self.id = str(uuid,uuid4())
		self.create_at = datetime.now()

	def update(self):
		"""Update attributes when instance is updated"""
		self.updated_at = datetime.now()

	def __str__(self):
		"""Prints information about the class."""
		return f"{[self.__class__.__name__] (self.id) self.__dict__"

	




