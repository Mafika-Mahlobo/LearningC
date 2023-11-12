#!/usr/bin/python3

"""Defines a base class with all common attributes/methods"""

from datetime import datetime
import uuid
import models


class BaseModel:

	"""Defines all common attributes/methods for other classes."""

	def __init__(self, *args, **kwargs):
		"""Initializes attributes when instance is created."""

		time_form = "%Y-%m-%dT%H:%M:%S.%f"
		self.id = str(uuid.uuid4())
		self.created_at = datetime.now()
		self.updated_at = datetime.now()

		if len(kwargs) != 0:
			for k, v in kwargs.items():
				if k == "created_at" or k == "updated_at":
					self.__dict__[k] = datetime.strptime(v, time_form)
				else:
					self.__dict__[k] = v
		else:
			models.storage.new(self)

	def save(self):
		"""Update attributes when instance is updated"""
		self.updated_at = datetime.now()
		models.storage.save()

	def __str__(self):
		"""Prints information about the class."""
		return f"[{self.__class__.__name__}] ({self.id}) {self.__dict__}"

	def to_dict(self):

		"""Returns a dict of the instace attributes (key/value pairs)"""
		instance_dict = self.__dict__
		instance_dict['__class__'] = self.__class__.__name__

		self.created_at = self.created_at.isoformat()
		self.updated_at = self.updated_at.isoformat()

		return instance_dict
