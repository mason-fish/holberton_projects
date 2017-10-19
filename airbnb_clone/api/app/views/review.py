from flask import jsonify
from flask_json import request
from app.models.user import User
from app.models.review import Review
from app.models.place import Place
from app.models.review_user import ReviewUser
from app.models.review_place import ReviewPlace
from app import app
from return_styles import ListStyles

@app.route('/reviews', methods=['GET'], strict_slashes=False)
def all_reviews():
    try:
        query = Review.select()
        return ListStyles.list(query, request), 200
    except:
        return jsonify({'code': 404, 'msg': "table does not yet exist in db"}), 404

'''
route /users/<user_id>/reviews:
GET: list of all reviews for a user (selected by user_id) => reviews received to the user
POST: create a new review from POST data parameters on the selected user (from user should be set by ID).
'''
@app.route('/users/<user_id>/reviews', methods=['GET', 'POST'], strict_slashes=False)
def user_reviews(user_id):
    try:
        User.select().where(User.id == user_id).get()
    except User.DoesNotExist:
        return jsonify({'code': 404, 'msg': "There is no user with this id."}), 404

    if request.method == 'GET':
        query = (Review
            .select()
            .join(ReviewUser)
            .where(ReviewUser.user == user_id))

        return ListStyles.list(query, request), 200

    elif request.method == 'POST':
        try:
            if request.form['message'] is None or request.form['user'] is None:
                return jsonify({'code': 404, 'msg': "Missing required data."}), 404
        except KeyError:
            return jsonify({'code': 400, 'msg': "Missing parameter."}), 400

        try:
            review = Review()
            [setattr(review, key, value) for (key, value) in request.form.items() if key != "created_at" and key != "updated_at"]
            review.save()

            ReviewUser.create(user=user_id, review=review.id)

            return jsonify(review.to_dict()), 201
        except:
            return jsonify({"code": 409, "msg": "user from data does not exist in db"}), 409

'''
route /users/<user_id>/reviews/<review_id>:
GET: review with id = review_id
DELETE: delete review with id = review_id
'''
@app.route('/users/<user_id>/reviews/<review_id>', methods=['GET', 'DELETE'], strict_slashes=False)
def user_reviews_id(user_id, review_id):    
    try:
        query_one = ReviewUser.select().where(ReviewUser.user == user_id, ReviewUser.review == review_id).get()
    except:
        return jsonify({"code": 404, "msg": "record does not exist in db, check user id and review id"}), 404 

    if request.method == "GET":
        query = Review.get(Review.id == review_id)
        return jsonify(query.to_dict()), 200
    elif request.method == "DELETE":
        query_two = Review.get(Review.id == review_id)
        query_one.delete_instance()
        query_two.delete_instance()
        return jsonify({"code": 200, "msg": "success"}), 200

'''
route /places/<place_id>/reviews:
GET: list of all reviews for a place (selected by place_id)
POST: create a new review from POST data parameters on the selected place (from user should be set by ID).
'''
@app.route('/places/<place_id>/reviews', methods=['GET', 'POST'], strict_slashes=False)
def place_reviews(place_id):
    try:
        Place.select().where(Place.id == place_id).get()
    except Place.DoesNotExist:
        return jsonify({'code': 404, 'msg': "There is no place with this id."}), 404
  
    if request.method == 'GET':
        query = (Review
            .select()
            .join(ReviewPlace)
            .where(ReviewPlace.place == place_id))
            
        return ListStyles.list(query, request), 200

    elif request.method == 'POST':
        try:
            if request.form['message'] is None or request.form['user'] is None:
                return jsonify({'code': 404, 'msg': "Missing required data."}), 404
        except KeyError:
            return jsonify({'code': 400, 'msg': "Missing parameter."}), 400

        try:
            review = Review()
            [setattr(review, key, value) for (key, value) in request.form.items() if key != "created_at" and key != "updated_at"]
            review.save()

            ReviewPlace.create(place=place_id, review=review.id)

            return jsonify(review.to_dict()), 201
        except:
            return jsonify({"code": 409, "msg": "error creating record, check input data"}), 409

'''
route /places/<place_id>/reviews/<review_id>:
GET: review with id = review_id
DELETE: delete review with id = review_id
'''
@app.route('/places/<place_id>/reviews/<review_id>', methods=['GET', 'DELETE'], strict_slashes=False)
def place_reviews_id(place_id, review_id):    
    try:
        query_one = ReviewPlace.select().where(ReviewPlace.place == place_id, ReviewPlace.review == review_id).get()
    except:
        return jsonify({"code": 404, "msg": "record does not exist in db, check place id and review id"}), 404 

    if request.method == "GET":
        query = Review.select().where(Review.id == review_id).get()
        return jsonify(query.to_dict()), 200
    elif request.method == "DELETE":
        query_two = Review.get(Review.id == review_id)
        query_one.delete_instance()
        query_two.delete_instance()
        return jsonify({"code": 200, "msg": "success"}), 200
