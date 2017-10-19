import unittest
from flask_json import JsonTestResponse
import logging
from app import app
from app.views import *
from app.models.place_book import PlaceBook
from app.models.city import City
from app.models.place import Place
from app.models.user import User
from app.models.state import State
from app.models.base import db
from peewee import *
from datetime import datetime


class FlaskTestCase(unittest.TestCase):
    def setUp(self):
        self.app = app
        self.app.response_class = JsonTestResponse
        self.client = app.test_client()
        logging.disable(logging.CRITICAL)
        db.create_tables([User, State, City, Place, PlaceBook], safe=True)

        self.client.post('/users', data={
            'first_name': "test",
            'last_name': "test",
            'email': "test",
            'password': "test"
        })

        self.client.post('/states', data={'name': "test"})

        self.client.post('/states/1/cities', data={
            'name': "test",
            'state': 1
        })

        self.client.post('/places', data={
            'owner': 1,
            'city': 1,
            'name': "test",
            'description': "test",
            'latitude': 0,
            'longitude': 0
        })

    def tearDown(self):
        db.drop_tables([User, State, City, Place, PlaceBook])

    def create_placebook(self, route, datetime_string, desc):
        return self.client.post(route, data={
            'place': 1,
            'user': 1,
            'date_start': datetime_string,
            'description': desc,
            'latitude': 0,
            'longitude': 0
        })

    def test_create(self):
        for i in range(1, 3):
            r = self.create_placebook('/places/1/books',
                datetime.now().strftime("%Y/%m/%d %H:%M:%S"),
                'test_' + str(i))

            assert r.json['id'] == i, (
                "ID should be incrementing"
            )

        r = self.client.get('/places/1/books')
        assert len(r.json['data']) == 2, (
            "Should return two records"
        )

        r = self.create_placebook('/places/1/books',
            '07/21/2016 13:00:16',
            'test')

        assert r.status_code == 400, (
            "Should return a 400 status code"
        )

    def test_create_id(self):
        for i in range(1, 3):
            self.create_placebook('/places/1/books',
                datetime.now().strftime("%Y/%m/%d %H:%M:%S"),
                'test_' + str(i))

        r = self.client.get('/places/1/books/2')
        assert r.json['id'] == 2, (
            "Record's ID should equal 2"
        )

        self.client.put('/places/1/books/2', data={
            'is_validated': True,
        })

        r = self.client.get('/places/1/books/2')
        assert r.json['is_validated'] == True, (
            "'is_validated' attribute was not updated properly"
        )

        r = self.client.put('/places/2/books/2', data={
            'user': 2,
        })
        assert r.status_code == 404, (
            "Should not be allowed to change book user, return 404 status code"
        )

    def test_delete(self):
        for i in range(1, 3):
            self.create_placebook('/places/1/books',
                datetime.now().strftime("%Y/%m/%d %H:%M:%S"),
                'test_' + str(i))

        self.client.delete('/places/1/books/1')

        r = self.client.get('/places/1/books')
        assert len(r.json['data']) == 1, (
            "Should return one record"
        )
        assert r.json['data'][0]['id'] == 2, (
            "Remaining record's ID should equal 2"
        )

if __name__ == '__main__':
    unittest.main()
