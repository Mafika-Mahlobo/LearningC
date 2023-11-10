#!/usr/bin/python3

"""Defines a base class with all common attributes/methods"""

from datetime import datetime
import uuid


class BaseModel:

	"""Defines all common attributes/methods for other classes."""

	def __init__(self):
		"""Initializes attributes when instance is created."""
		self.id = str(uuid.uuid4())
		self.create_at = datetime.now()
		self.update_at = datetime.now()

	def save(self):
		"""Update attributes when instance is updated"""
		self.updated_at = datetime.now()

	def __str__(self):
		"""Prints information about the class."""
		return f"[{self.__class__.__name__}] ({self.id}) {self.__dict__}"

	def to_dict(self):

		"""Returns a dict of the instace attributes (key/value pairs)"""
		instance_dict = self.__dict__
		instance_dict['__class__'] = self.__class__.__name__

		self.create_at = self.create_at.isoformat()
		self.update_at = self.update_at.isoformat()

		return instance_dict

		



	




