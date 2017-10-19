from peewee import *
from base import BaseModel
import hashlib
'''
User defines a user object which contains information
about each user in the database.
'''
class User(BaseModel):
    email = CharField(128, null=False, unique=True)
    password = CharField(128, null=False)
    first_name = CharField(128, null=False)
    last_name = CharField(128, null=False)
    is_admin = BooleanField(default=False)

    def set_password(self, clear_password):
        self.password = hashlib.md5(clear_password).hexdigest()
    
    def to_dict(self):
        data = {
            'id': self.id,
            'created_at': self.created_at.strftime("%Y/%m/%d %H:%M:%S"),
            'updated_at': self.updated_at.strftime("%Y/%m/%d %H:%M:%S"),
            'email': self.email,
            'first_name': self.first_name,
            'last_name': self.last_name,
            'is_admin': self.is_admin
        }

        return data
        
    
