#!/usr/bin/python3
"""
Module containing a call to serializes and deserializes JSON file to instances and vise-vesa
"""
import json
from models.base_model import BaseModel

class FileStorage:

	"""Serializes instances to a JSON file and deserializes JSON file to instances."""

	__file_path = "file.json"
	__objects = {}

	def all(self):
		"""returns objects (dictionary)"""
		return FileStorage.__objects

	def new(self, obj):
		"""sets in __objects the obj with key <obj class name>.id"""
		obj_class_name = obj.__class__.__name__
		FileStorage.__objects[f"{obj_class_name}.{obj.id}"] = obj

	def save(self):
		"""serializes __objects to the JSON file (path: __file_path)"""

		objs_dict = FileStorage.__objects
		objdict = {obj: objs_dict[obj].to_dict() for obj in objs_dict.keys()}
	

		with open(FileStorage.__file_path, "w") as f:
			json.dump(objdict, f)

	def reload(self):
		"""deserializes the JSON file to __objects"""
		try:
			with open(FileStorage.__file_path) as f:
				objdict = json.load(f)

				for o in objdict.values():
					cls_name = o["__class__"]
					del o["__class__"]
					self.new(eval(cls_name)(**o))
		except FileNotFoundError:
			return

	
