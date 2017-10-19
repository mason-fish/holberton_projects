import unittest
import json
import logging
from app import app
from flask_json import JsonTestResponse
from app.models.state import State
from app.models.base import db
from peewee import *

class FlaskTestCase(unittest.TestCase):
    def setUp(self):
        self.app = app
        logging.disable(logging.CRITICAL)
        self.app.response_class = JsonTestResponse
        self.client = self.app.test_client()
        db.create_tables([State], safe=True)

    def tearDown(self):
        db.drop_table(State)

    def post_data(self, route, **data):
        data_list = {
            'name': "California"
        }
        for key, value in data.iteritems():
            data_list[key] = value

        return self.client.post(route, data=data_list)

    def test_create(self):
        for i in range(1, 3):
            res = self.post_data('/states', name=("state_name_" + str(i)))
            assert res.json['id'] == i, (
                "Primary key is not incrementing"
            )

        assert self.post_data('/states', name=None).status_code == 409, (
            "Missing parameter should return 409"
        )
        assert self.post_data('/states', name=("state_name_" + str(i))).status_code == 409, (
            "Non unique names posted should return 409"
        )

    def test_list(self):
        assert len(self.client.get('/states').json['data']) == 0, (
            "Should not return data if db is empty"
        )
        
        new = self.post_data('/states').json
        res = self.client.get('/states/1').json
        assert len(new) == len(set(new) & set(res)), (
            "Responses from first post and following get should match"
        )

    def test_delete(self):
        new = self.post_data('/states').json
        check = self.client.get('/states/1')
        
        assert check.status_code == 200, (
            "Successful get state by id should return 200"
        )

        assert len(new) == len(set(new) & set(check.json)), (
            "Data from created state and get by id should match"
        )

        assert self.client.delete('/states/1').status_code == 200, (
            "Successful delete by state id should return 200"
        )

        assert len(self.client.get('/states').json['data']) == 0, (
            "No elements should remain in table after deletion"
        )

        assert self.client.delete('/states/10').status_code == 404, (
            "Attempt to delete non existent item in db should return 404"
        )
        
if __name__ == '__main__':
    unittest.main()
