from flask_json import request
from flask import jsonify
from app.models.city import City
from app.models.state import State
from app import app
from peewee import *
from return_styles import ListStyles

'''
route /states/<state_id>/cities/<city_id>:
GET: city with id = city_id
DELETE: delete city with id = city_id
'''
@app.route('/states/<state_id>/cities/', methods=["GET", "POST"], strict_slashes=False)
def app_cities(state_id):
    if request.method == "GET":
        try:
            query = City.select().where(City.state == state_id)
            return ListStyles.list(query, request), 200
        except City.DoesNotExist:
            return jsonify({"code": 404, "msg": "not found"}), 404
    
    elif request.method == "POST":
        if City.select().where(City.state == state_id, City.name == request.form['name']).exists():
            return jsonify({"code": 10002, "msg": "City already exists in this state"}), 409
        
        new = City.create(
            name=str(request.form['name']),
            state=int(state_id)
        )
        return jsonify(new.to_dict()), 201
    

@app.route('/states/<state_id>/cities/<city_id>/', methods=["GET", "DELETE"], strict_slashes=False)
def app_cities_id(state_id, city_id):
    if request.method == "GET":
        try:
            query = City.get(City.id == city_id)
            return jsonify(query.to_dict()), 200
        except:     
            return jsonify({"code": 404, "msg": "not found"}), 404
    
    elif request.method == "DELETE":
        try:
            query = City.get(City.id == city_id)
            query.delete_instance()
            return jsonify({"code": 200, "msg": "success"}), 200
        except:     
            return jsonify({"code": 404, "msg": "not found"}), 404
