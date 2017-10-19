import unittest
import logging
from flask_json import JsonTestResponse
from app import app
from app.views import *
from app.models.city import City
from app.models.state import State
from app.models.base import db
from peewee import *


class FlaskTestCase(unittest.TestCase):

    def setUp(self):
        self.app = app
        self.app.response_class = JsonTestResponse
        self.client = self.app.test_client()
        logging.disable(logging.CRITICAL)
        db.create_tables([State, City], safe=True)

        self.client.post('/states', data={'name': "test"})

    def tearDown(self):
        db.drop_tables([State, City])

    def create_city(self, city_name):
        return self.client.post('/states/1/cities', data={
            'name': city_name,
            'state': 1
        })

    def test_create(self):
        for i in range(1, 3):
            r = self.create_city("test_" + str(i))
            assert r.json['id'] == i, (
                "ID should be incrementing"
            )

        r = self.client.post('/states/1/cities', data={'bad_param': "test"})
        assert r.status_code == 400, (
            "Bad parameter should return 400 status code"
        )
        
        r = self.create_city("test_2")
        assert r.status_code == 409, (
            "Non unique name should return 409 status code"
        )

    def test_list(self):
        r = self.client.get('/states/1/cities')
        assert len(r.json['data']) == 0, (
            "Should not return any records from an empty table"
        )

        self.create_city("test")
        r = self.client.get('/states/1/cities')
        assert len(r.json['data']) == 1, (
            "Should return one record from a table with one record"
        )

    def test_create_with_id(self):
        for i in range(1, 3):
            self.create_city("test_" + str(i))

        r = self.client.get('/states/1/cities/2')
        assert r.json['id'] == 2, (
            "Record's ID should equal 2'"
        )

    def test_delete(self):
        for i in range(1, 3):
            self.create_city("test_" + str(i))

        r = self.client.delete('/states/1/cities/1')
        assert r.status_code == 200, (
            "Successful delete of a record should return 200 status code"
        )

        r = self.client.get('/states/1/cities')
        assert r.json['data'][0]['id'] == 2, (
            "Remaining record's ID should equal 2'"
        )

if __name__ == '__main__':
    unittest.main()
