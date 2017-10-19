from peewee import *
from app.models.user import User
from flask_json import request
from app import app
from flask import jsonify
from return_styles import ListStyles

@app.route('/users/', methods=["GET", "POST"], strict_slashes=False)
def app_users():
    if request.method == "GET":
        query = User.select()
        return ListStyles.list(query, request), 200
    
    elif request.method == "POST":
        try:
            new = User.create(
                email=str(request.form['email']),
                first_name=str(request.form['first_name']),
                last_name=str(request.form['last_name']),
                password=""                
            )
            new.set_password(str(request.form['password']))
            return jsonify(new.to_dict()), 201
        except:
            return jsonify({'code': 10000, 'msg': "BAD!"}), 409


@app.route('/users/<user_id>/', methods=["GET", "PUT", "DELETE"], strict_slashes=False)
def app_users_id(user_id):
    if request.method == "GET":
        try:
            query = User.get(User.id == user_id)
            return jsonify(query.to_dict()), 200
        except User.DoesNotExist:
            return jsonify({"code": 404, "msg": "not found"}), 404

    elif request.method == "PUT":
        try:
            query = User.get(User.id == user_id)
            return_query = query
            [setattr(query, key, value) for (key, value) in request.form.items() if key != "updated_at" and key != "created_at"]
            query.save()
            return jsonify(return_query.to_dict()), 201
        except:
            return jsonify({"code": 404, "msg": "not found"}), 404
    
    elif request.method == "DELETE":
        try:
            query = User.get(User.id == user_id)
            query.delete_instance()
            return jsonify({"code": 200, "msg": "success"}), 200
        except:
            return jsonify({"code": 404, "msg": "not found"}), 404
            

