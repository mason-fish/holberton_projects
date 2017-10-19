from peewee import *
from app.models.amenity import Amenity
from app.models.place import Place
from app.models.place_amenity import PlaceAmenities
from flask import jsonify
from flask_json import request
from app import app
from return_styles import ListStyles

'''
route /amenities:
GET: list of all amenities
POST: create a new amenity from POST data parameters. If the name is already taken in the database, return an error (code: 10003, msg: "Name already exists" ; header HTTP status code: 409)

route /amenities/<amenity_id>:
GET: amenity with id = amenity_id
DELETE: delete amenity with id = book_id

route /places/<place_id>/amenities:
GET: list of all amenities for the selected place
'''

@app.route('/amenities/', methods=["GET", "POST"], strict_slashes=False)
def app_amenities():
    if request.method == "GET":
        try:
            query = Amenity.select()
            if not query.exists():
                return jsonify({"code": 404, "msg": "not found"}), 404
            return ListStyles.list(query, request), 200
        except:
            return jsonify({"code": 404, "msg": "not found"}), 404

    elif request.method == "POST":
        try:
            new = Amenity.create(
                name=request.form['name']
            )
            return jsonify(new.to_dict()), 201
        except:
            return jsonify({"code": 10003, "msg": "Name already exists"}), 409

@app.route('/amenities/<amenity_id>/', methods=["GET", "DELETE"], strict_slashes=False)
def app_amenities_id(amenity_id):
    if request.method == "GET":
        try:
            query = Amenity.get(Amenity.id == amenity_id)
            return ListStyles.list(query, request), 200
        except:
            return jsonify({"code": 404, "msg": "not found"}), 404

    elif request.method == "DELETE":
        try:
            query = Amenity.get(Amenity.id == amenity_id)
            query.delete_instance()

            return jsonify({"code": 200, "msg": "success"}), 200
        except:
            return jsonify({"code": 404, "msg": "not found"}), 404

@app.route('/places/<place_id>/amenities/', methods=["GET"], strict_slashes=False)
def app_amenities_place(place_id):
    if request.method == "GET":
        try:
            query = Amenity.select().join(PlaceAmenities).where(PlaceAmenities.place == place_id)
            return ListStyles.list(query, request), 200
        except:
            return jsonify({"code": 404, "msg": "not found"}), 404

@app.route('/places/<place_id>/amenities/<amenity_id>', methods=["POST", "DELETE"], strict_slashes=False)
def app_create_delete_amenity(place_id, amenity_id):
    try:
        Place.get(Place.id == place_id)
    except Place.DoesNotExist:
        return jsonify({"code": 409, "msg": "place id does not exist"}), 409
    try:
        Amenity.get(Amenity.id == amenity_id)
    except Amenity.DoesNotExist:
        return jsonify({"code": 409, "msg": "amenity id does not exist"}), 409

    if request.method == "POST":
        if PlaceAmenities.select().where(PlaceAmenities.place == place_id, PlaceAmenities.amenity == amenity_id).exists():
            return jsonify({"code": 409, "msg": "Place already has this amenity"}), 409

        PlaceAmenities.create(
            place=place_id,
            amenity=amenity_id
        )
        return jsonify({"code": 200, "msg": "success"}), 200

    elif request.method == "DELETE":
        try:
            query = PlaceAmenities.select().where(PlaceAmenities.place == place_id, PlaceAmenities.amenity == amenity_id).get()
            query.delete_instance()
            return jsonify({"code": 200, "msg": "success"}), 200
        except:
            return jsonify({"code": 404, "msg": "not found"}), 404

