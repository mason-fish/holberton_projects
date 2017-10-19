from peewee import *
from base import db
from review import Review
from user import User

class ReviewUser(Model):
    user = ForeignKeyField(User)
    review = ForeignKeyField(Review)

    class Meta:
        database = db