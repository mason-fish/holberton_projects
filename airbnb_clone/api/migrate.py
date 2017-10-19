from peewee import *
from app.models import *

def create_tables():
    db_tables = [
                amenity.Amenity, 
                city.City,
                place.Place,
                place_amenity.PlaceAmenities,
                place_book.PlaceBook,
                state.State,
                user.User,
                review.Review,
                review_user.ReviewUser,
                review_place.ReviewPlace
                ]

    try:
        base.db.create_tables(db_tables, safe=True)
    except peewee.OperationalError:
        pass

create_tables()

