import unittest
import json
import logging
from flask_json import JsonTestResponse
from app import app
from app.views import *
from app.models.amenity import Amenity
from app.models.base import db
from peewee import *
from datetime import datetime


class FlaskTestCase(unittest.TestCase):

    def setUp(self):
        self.app = app
        self.app.response_class = JsonTestResponse
        logging.disable(logging.CRITICAL)
        self.client = self.app.test_client()
        db.create_tables([Amenity], safe=True)

    def tearDown(self):
        db.drop_tables([Amenity])

    def create_amenity(self, route, amenity_name):
        return self.client.post(route, data={
            'name': amenity_name
        })

    def test_create(self):
        for i in range(1, 3):
            r = self.create_amenity('/amenities', 'test_' + str(i))
            assert r.json['id'] == i, (
                "Primary key is not incrementing"
            )
            
        r = self.client.get('/amenities')
        assert len(r.json['data']) == 2, (
            "Should return two records"
        )
        
        r = self.create_amenity('/amenities', "test_2")
        assert r.status_code == 409, (
            "Duplicate names should return 409 status code"
        )

    def test_delete(self):
        for i in range(1, 3):
            self.create_amenity('/amenities', 'test_' + str(i))

        r = self.client.delete('/amenities/1')
        assert r.status_code == 200, (
            "Successful delete should return 200 status code"
        )

        '''There is only one remaining booking in the table, that with id 2.'''
        r = self.client.get('/amenities')
        assert len(r.json['data']) == 1, (
            "Should only return one record"
        )
        assert r.json['data'][0]['id'] == 2, (
            "ID of remaining record should be 2"
        )

if __name__ == '__main__':
    unittest.main()
