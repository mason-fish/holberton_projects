from base import BaseModel
from user import User
from peewee import *

class Review(BaseModel):
    message = TextField()
    stars = IntegerField(default=0)
    user = ForeignKeyField(
        User,
        related_name="reviews",
        on_delete="CASCADE"
    )

    def to_dict(self):
        from review_user import ReviewUser
        from review_place import ReviewPlace

        items = {
            'id': self.id,
            'created_at': self.created_at.strftime("%Y/%m/%d %H:%M:%S"),
            'updated_at': self.updated_at.strftime("%Y/%m/%d %H:%M:%S"),
            'message': self.message,
            'stars': self.stars,
            'fromuser_id': self.user_id
        }

        try:
            query = ReviewUser.select().where(ReviewUser.review == self.id).get()
            items['touser_id'] = query.user_id
        except:
            items['touser_id'] = None
        try:
            query = ReviewPlace.select().where(ReviewPlace.review == self.id).get()
            items['toplace_id'] = query.place_id
        except:
            items['toplace_id'] = None
        
        return items 