from peewee import *
from base import BaseModel
from state import State

class City(BaseModel):
    name = CharField(128, null=False)
    state = ForeignKeyField(
        State,
        related_name="cities",
        on_delete="CASCADE"
    )

    def to_dict(self):
        data = {
            'id': self.id,
            'created_at': self.created_at.strftime("%Y/%m/%d %H:%M:%S"),
            'updated_at': self.updated_at.strftime("%Y/%m/%d %H:%M:%S"),
            'name': self.name,
            'state_id': self.state_id
        }

        return data