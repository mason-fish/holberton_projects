from peewee import *
from base import BaseModel

class State(BaseModel):
    name = CharField(128, null=False, unique=True)

    def to_dict(self):
        data = {
            'id': self.id,
            'created_at': self.created_at.strftime("%Y/%m/%d %H:%M:%S"),
            'updated_at': self.updated_at.strftime("%Y/%m/%d %H:%M:%S"),
            'name': self.name,
        }

        return data

