import unittest
import logging
from flask_json import JsonTestResponse
from app import app
from app.views import *
from app.models.place import Place
from app.models.user import User
from app.models.state import State
from app.models.city import City
from app.models.base import db
from peewee import *


class FlaskTestCase(unittest.TestCase):

    def setUp(self):
        self.app = app
        self.app.response_class = JsonTestResponse
        self.client = self.app.test_client()
        logging.disable(logging.CRITICAL)
        db.create_tables([User, City, Place, State], safe=True)

        self.client.post('/states', data={'name': "test"})
        self.client.post('/states/1/cities', data={
            'name': "test",
        })
        self.client.post('/users', data={
            'first_name': "test",
            'last_name': "test",
            'email': "test",
            'password': "test"
        })

    def tearDown(self):
        db.drop_tables([User, City, Place, State])

    def create_place(self, route, name="test", city=1):
        attributes = {
            'owner': 1,
            'city': city,
            'name': name,
            'description': "test",
            'latitude': 0,
            'longitude': 0
        }
        return self.client.post(route, data=attributes)


    # def test_create(self):
    #     for i in range(1, 3):
    #         r = self.create_place('/places', 'test_' + str(i))
    #         assert r.json['id'] == i, (
    #             "ID should be incrementing"
    #         )

    # def test_create_id(self):
    #     for i in range(1, 3):
    #         r = self`.create_place('/places', 'test_' + str(i))
    #         assert r.json['name'] == "test_" + str(i), (
    #             "Create_place() function is not worling as expected"
    #         )

    #     r = self.client.get('/places/2')
    #     assert r.json['id'] == 2, (
    #         "Record's ID should equal 2"
    #     )

    #     self.client.put('/places/2', data={'name': "updated_data"})
    #     r = self.client.get('/places/2')
    #     assert r.json['name'] == "updated_data", (
    #         "Record's name is not updating properly'"
    #     )

    #     r = self.client.put('/places/1', data={'owner': "test"})
    #     assert r.status_code == 404, (
    #         "Should not be allowed to change owner name, return 404 status code"
    #     )

    #     r = self.client.put('/places/1', data={'city': "test"})
    #     assert r.status_code == 404, (
    #         "Should not be allowed to change city name, return 404 status code"
    #     )

    # def test_delete(self):
    #     for i in range(1, 3):
    #         self.create_place('/places', 'test_' + str(i))

    #     self.client.delete('/places/2')
        
    #     r = self.client.get('/places')
    #     assert len(r.json['data']) == 1, (
    #         "Should return one record after delete"
    #     )
    #     assert r.json['data'][0]['id'] == 1, (
    #         "Remaining record's ID should equal 1"
    #     )    

    # def test_get_places_by_id(self):
    #     for i in range(1, 3):
    #         self.create_place('/places', 'test_' + str(i))
        
    #     r = self.client.get('/states/1/cities/1/places')
    #     assert len(r.json['data']) == 2, (
    #         "Should return two records"
    #     )

    #     self.client.post('/states/1/cities/1/places', data={
    #         'owner': 1,
    #         'city': 1,
    #         'name': "test",
    #         'description': "test",
    #         'latitude': 0,
    #         'longitude': 0
    #     })
    #     r = self.client.get('/states/1/cities/1/places')
    #     assert len(r.json['data']) == 3, (
    #         "Should return three records"
    #     )

    def setup_for_places_in_states(self):
        self.client.post('/states', data={'name': "test2"})
        for i in range(3):
            self.client.post('/states/1/cities', data={
                'name': "test" + str(i)
            })
        for i in range(4):
            self.client.post('/states/2/cities', data={
                'name': "b_test" + str(i)
            })
        for i in range(1, 4):
            self.create_place('/places', name="one_" + str(i), city=i)
        for i in range(4, 9):
            self.create_place('/places', name="two_" + str(i), city=i)

    def test_get_places_in_state(self):
        self.setup_for_places_in_states()
        r = self.client.get('/states/1/places')
        i = 1
        for record in r.json['data']:
            assert record['id'] == i, (
                'places are not properly retrieved by first state'
            )
            i += 1
        r = self.client.get('/states/2/places')
        for record in r.json['data']:
            assert record['id'] == i, (
                'places are not properly retrieved by second state'
            )
            i += 1

if __name__ == '__main__':
    unittest.main()
