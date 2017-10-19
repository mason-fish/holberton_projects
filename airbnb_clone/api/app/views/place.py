from peewee import *
from app.models.place import Place
from app.models.place_book import PlaceBook
from app.models.city import City
from app.models.state import State
from flask import jsonify
from flask_json import request
from app import app
from return_styles import ListStyles
import datetime

'''
route /places:
GET: list of all places
POST: create a new place from POST data parameters (owner and city should be set by ID).

route /places/<place_id>:
GET: place with id = place_id
PUT: update the place with id = place_id with PUT data parameters. owner and city can't be changed
DELETE: delete place with id = place_id

route /states/<state_id>/cities/<city_id>/places:
GET: list of all places in the selected city
POST: create a new place from POST data parameters in the selected city.
'''

@app.route('/places/', methods=["GET", "POST"], strict_slashes=False)
def app_places():
    if request.method == "GET":
        try:
            query = Place.select()
            return ListStyles.list(query, request), 200
        except:
            return jsonify({"code": 404, "msg": "not found"}), 404

    if request.method == "POST":
        try:
            new = Place.create(
                owner=int(request.form['owner']),
                city=int(request.form['city']),
                name=str(request.form['name']),
                description=str(request.form['description']),
                latitude=float(request.form['latitude']),
                longitude=float(request.form['longitude'])
            )
            return jsonify(new.to_dict()), 201
        except:
            return jsonify({"code": 10004, "msg": "Place cannot be"}), 409  

@app.route('/places/<place_id>/', methods=["GET", "PUT", "DELETE"], strict_slashes=False)
def app_places_id(place_id):
    if request.method == "GET":
        try:
            query = Place.get(Place.id == place_id)
            return jsonify(query.to_dict()), 200
        except:
            return jsonify({"code": 404, "msg": "not found"}), 404

    elif request.method == "PUT":
        try:
            query = Place.get(Place.id == place_id)
            [setattr(query, key, value) for (key, value) in request.form.items() if key != "updated_at" and key != "created_at"]
            query.save()
            return jsonify(query.to_dict()), 200
        except:
            return jsonify({"code": 404, "msg": "not found"}), 404

    elif request.method == "DELETE":
        try:
            query = Place.get(Place.id == place_id)
            query.delete_instance()
            return jsonify({"code": 200, "msg": "success"}), 200
        except:
            return jsonify({"code": 404, "msg": "not found"}), 404

@app.route('/states/<state_id>/places', methods=["GET"], strict_slashes=False)
def places_in_state(state_id):
    try:
        State.get(State.id == state_id)
    except State.DoesNotExist:
        return jsonify({'code': 404, 'msg': "State does not exist in the database"}), 404
    query = Place.select().join(City).join(State).where(State.id == state_id)
    return ListStyles.list(query, request), 200

@app.route('/states/<state_id>/cities/<city_id>/places/', methods=["GET", "POST"], strict_slashes=False)
def app_city_places(state_id, city_id):
    if request.method == "GET":
        query = Place.select().join(City).where(Place.city == city_id, City.state == state_id)
        if query.exists():    
            return ListStyles.list(query, request), 200
        else:
            return jsonify({"code": 404, "msg": "not found"}), 404            

    elif request.method == "POST":
        if City.select().where(City.id == city_id, City.state == state_id).exists():
            new = Place.create(
                owner=int(request.form['owner']),
                city=int(city_id),
                name=str(request.form['name']),
                description=str(request.form['description']),
                latitude=float(request.form['latitude']),
                longitude=float(request.form['longitude'])
            )
            return jsonify(new.to_dict()), 201

        else:
            return jsonify({"code": 404, "msg": "City does not exist in this state"}), 404

@app.route('/places/<place_id>/available', methods=["POST"], strict_slashes=False)
def check_availability(place_id):
    try:
        year = request.form['year']
        month = request.form['month']
        day = request.form['day']
    except KeyError:
        return jsonify({'code': 409, 'msg': "Form data must contain 'year', 'month', and 'day' to check availability"}), 409

    request_date = datetime.datetime.strptime(str(year) + str(month) + str(day), "%Y%m%d")

    list_place_bookings = PlaceBook.select().where(PlaceBook.place == place_id)

    for booking in list_place_bookings:
        start_date = datetime.datetime.strptime(booking.date_start.strftime("%Y%m%d"), "%Y%m%d")
        end_date = start_date + datetime.timedelta(days=booking.number_nights)
        if end_date >= request_date >= start_date:
            return jsonify({'available': False}), 200 

    return jsonify({'available': True}), 200