from peewee import *
from base import db
from review import Review
from place import Place

class ReviewPlace(Model):
    place = ForeignKeyField(Place)
    review = ForeignKeyField(Review)

    class Meta:
        database = db
