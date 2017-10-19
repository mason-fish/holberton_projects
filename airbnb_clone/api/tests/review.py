import unittest
import logging
from flask_json import JsonTestResponse
from app import app
from app.views import *
from app.models.user import User
from app.models.review import Review
from app.models.review_user import ReviewUser
from app.models.place import Place
from app.models.review_place import ReviewPlace
from app.models.city import City
from app.models.state import State
from app.models.base import db
from peewee import *


class FlaskTestCase(unittest.TestCase):

    def setUp(self):
        self.app = app
        self.app.response_class = JsonTestResponse
        self.client = app.test_client()
        logging.disable(logging.CRITICAL)
        db.create_tables([
            User, 
            Place, 
            Review, 
            ReviewPlace,
            ReviewUser, 
            City, 
            State
            ], safe=True)

        for i in range(1, 3):
            self.client.post('/users', data={
                'first_name': "user_" + str(i),
                'last_name': "user_" + str(i),
                'email': "user_" + str(i),
                'password': "user_" + str(i)
            })

        self.client.post('/states', data={
            'name': "state_1"
        })
        self.client.post('/states/1/cities', data={
            'name': "city_1", 
            'state': 1
        })
        self.client.post('/places', data={
            'owner': 1, 
            'city': 1, 
            'name': "place_1",
            'description': "place_1", 
            'latitude': 0,
            'longitude': 0
        })

    def tearDown(self):
        db.drop_tables([
            User,
            Place, 
            Review, 
            ReviewPlace,
            ReviewUser, 
            City, 
            State])

    def create_review(self, route, message_str, user_id):
        return self.client.post(route, data={
            'message': message_str,
            'user': user_id 
        })

    def test_get_reviews(self):
        r = self.client.get('/users/2/reviews')
        assert len(r.json) == 0, (
            "Length of reviews should be 0 from a reviewless user"
        )

        self.create_review('/users/1/reviews', 'test', 2)
        r = self.client.get('/users/1/reviews')
        assert len(r.json) == 1, (
            "After creating a new review of user 2, the length should be 1."
        ) 

        r = self.client.get('/users/3/reviews')
        assert r.status_code == 404, (
            "Query for an unknown user id number should return 404 status."
        )

    def test_post_reviews(self):
        r = self.create_review('/users/3/reviews', 'test', 2)
        assert r.status_code == 404, (
            "Query for an unknown user id number should return 404 status."
        )

        for i in range(1, 3):
            r = self.create_review('/users/1/reviews', 'test', 2)
            assert int(r.json['touser_id']) == 1, (
                "touser_id should equal 1"
            )
            assert int(r.json['fromuser_id']) == 2, (
                "fromuser_id should equal 2"
            ) 
            assert r.json['id'] == i, (
                "review id is not incrementing"
            )
            
        '''Test for a cases where required parameters are missing or improper
        types are passed as parameter (e.g., an string instead of an int).'''
        no_message = self.client.post('/users/1/reviews', data={
            'user': 2
        })
        assert no_message.status_code == 400, (
            "missing required parameter (message) should not succeed"
        )
        no_user = self.client.post('/users/1/reviews', data={
            'message': "test"
        })
        assert no_user.status_code == 400, (
            "missing required parameter (user) should not succeed"
        )

    def test_list(self):
        for i in range(1, 3):
            self.create_review('/users/1/reviews', 'test_' + str(i), 2)

        r = self.client.get('/users/1/reviews/1')
        assert r.json['message'] == "test_1", (
            "Message should equal 'test_1'"
        )

        r = self.client.get('/users/1/reviews/2')
        assert r.json['message'] == "test_2", (
            "Message should equal 'test_2'"
        )

        '''Test cases where the user or review ids do not exist.'''
        r = self.client.get('/users/3/reviews/1')
        assert r.status_code == 404, (
            "Should return nothing if user does not exist"
        )
        r = self.client.get('/users/1/reviews/3')
        assert r.status_code == 404, (
            "Should return nothing if review does not exist"
        )

    def test_delete(self):
        for i in range(1, 3):
            res = self.create_review('/users/1/reviews', 'test_' + str(i), 2)

        r = self.client.get('/users/1/reviews')
        assert len(r.json) == 2, (
            "There should two reviews for user 1."
        )

        r = self.client.delete('/users/1/reviews/1')
        assert r.status_code == 200, (
            "Delete review should return 200 status code."
        )

        r = self.client.get('/users/1/reviews')
        assert len(r.json['data']) == 1, (
            "After delete, there should be 1 review for user 1."
        )

        r = self.client.delete('/users/3/reviews/1')
        assert r.status_code == 404, (
            "Status code should return 404 if User does not exist"
        )

        r = self.client.delete('/users/1/reviews/3')
        assert r.status_code == 404, (
            "Status code should return 404 if Review does not exist"
        ) 

    def test_get_reviews(self):
        r = self.client.get('/users/1/reviews')
        assert len(r.json['data']) == 0, (
            "User should have no reviews returned"
        )
        
        self.create_review('/users/1/reviews', 'test', 2)
        r = self.client.get('/users/1/reviews')
        assert len(r.json['data']) == 1, (
            "User should have one review"
        )

    def test_get_place_review(self):
        r = self.client.get('/places/1/reviews')
        assert len(r.json['data']) == 0, (
            "Should not return any reviews when none are yet created"
        )

        r = self.client.get('/places/2/reviews')
        assert r.status_code == 404, (
            "Should return a 404 status code"
        )

        self.create_review('/places/1/reviews', 'test', 2)
        r = self.client.get('/places/1/reviews')
        assert len(r.json['data']) == 1, (
            "Should return only one review"
        )

    def test_post_place_review(self):
        r = self.client.get('/places/1/reviews')
        assert len(r.json) == 0, (
            "Should not return any reviews"
        )

        self.create_review('/places/1/reviews', 'test', 2)
        r = self.client.get('/places/1/reviews')
        assert len(r.json) == 1, (
            "Should return one review"
        )

        r = self.client.get('/places/2/reviews')
        assert r.status_code == 404, (
            "Should return a 404 status code"
        )

    def test_post_place_review(self):
        r = self.client.get('/places/1/reviews/1')
        assert r.status_code == 404, (
            "Should return a 404 status code"
        )

        self.create_review('/places/1/reviews', 'test', 2)
        r = self.client.get('/places/1/reviews/1')
        assert len([r.json]) == 1, (
            "Should return a single review"
        ) 
        assert r.json['id'] == 1, (
            "ID of review should be 1"
        )

    def test_delete_place_review(self):
        r = self.client.delete('/places/1/reviews/1')
        assert r.status_code == 404, (
            "Should return a 404 status code"
        )

        self.create_review('/places/1/reviews', 'test', 2)
        r = self.client.get('/places/1/reviews')
        assert len(r.json['data']) == 1, (
            "Should return a single review"
        )

        r = self.client.delete('/places/2/reviews/1')
        assert r.status_code == 404, (
            "Should return a status code of 404"
        )

        r = self.client.delete('/places/1/reviews/1')
        assert r.status_code == 200, (
            "Should return a 200 status code"
        )

        r = self.client.get('/places/1/reviews/1')
        assert r.status_code == 404, (
            "Should return a 404 status code"
        )

        r = self.client.get('/places/1/reviews')
        assert len(r.json['data']) == 0, (
            "Should not return any reviews, after deletion"
        )

if __name__ == '__main__':
    unittest.main()
