from peewee import *
from app.models.place_book import PlaceBook
from flask import jsonify
from flask_json import request
from app import app
import datetime
from return_styles import ListStyles

'''
route /places/<place_id>/books:
GET: list of all books for the selected place (by place_id)
POST: create a new book from POST data parameters (user should be set by ID) for the selected place. date_start should be to this format: yyyy/MM/dd HH:mm:ss

route /places/<place_id>/books/<book_id>:
GET: book with id = book_id
PUT: update the book with id = book_id with PUT data parameters. user can't be changed
DELETE: delete book with id = book_id
'''

@app.route('/places/<place_id>/books/', methods=["GET", "POST"], strict_slashes=False)
def app_books(place_id):
    if request.method == "GET":
        try:
            query = PlaceBook.select().where(PlaceBook.place == place_id)
            if not query.exists():
                raise Exception
            return ListStyles.list(query, request), 200
        except:
            return jsonify({"code": 404, "msg": "not found"}), 404

    elif request.method == "POST":
        try:
            dt_start = datetime.datetime.strptime(request.form['date_start'], '%Y/%m/%d %H:%M:%S')
        except ValueError:
            return jsonify({"code": 400, "msg": "improper date format"}), 400

        dt_end = dt_start + datetime.timedelta(days=int(request.form.get('number_nights', 1)))
        list_place_bookings = PlaceBook.select().where(PlaceBook.place == place_id)

        for booking in list_place_bookings:
            start_date = datetime.datetime.strptime(booking.date_start.strftime("%Y%m%d"), "%Y%m%d")
            end_date = start_date + datetime.timedelta(days=booking.number_nights)
            if (end_date >= dt_start >= start_date) or (end_date >= dt_end >= start_date):
                return jsonify({'code': 110000, 'msg': "Place unavailable at this date"}), 410
            
        try:
            new = PlaceBook.create(
                place=int(place_id),
                user=int(request.form['user']),
                date_start=dt_start,
                number_nights=int(request.form.get('number_nights', 1))
            )
            return jsonify(new.to_dict()), 200

        except:
            return jsonify({"code": 10006, "msg": "Booking error: place or user may not yet exist"}), 409

@app.route('/places/<place_id>/books/<book_id>/', methods=["GET", "PUT", "DELETE"], strict_slashes=False)
def app_books_id(place_id, book_id):
    if request.method == "GET":
        try:
            query = PlaceBook.get(PlaceBook.id == book_id)
            return jsonify(query.to_dict()), 200
            
        except:
            return jsonify({"code": 404, "msg": "not found"}), 404
    
    elif request.method == "PUT":
        try:
            query = PlaceBook.get(PlaceBook.id == book_id)
            [setattr(query, key, value) for (key, value) in request.form.items() if key != "updated_at" and key != "created_at"]
            query.save()
            return jsonify(query.to_dict()), 200

        except:
            return jsonify({"code": 404, "msg": "not found"}), 404

    elif request.method == "DELETE":
        try:
            query = PlaceBook.get(PlaceBook.id == book_id)
            query.delete_instance()
            return jsonify({"code": 200, "msg": "success"}), 200 

        except:
            return jsonify({"code": 404, "msg": "not found"}), 404
