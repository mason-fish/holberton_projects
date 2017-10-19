from peewee import *
from datetime import datetime
from app.models.base import *
from flask import *
from flask_json import *
from app import app
from MySQLdb import *

app.config['JSON_ADD_STATUS'] = False

@app.route('/', methods=["GET"])
@as_json
def index():
    res = {
        'status': "OK",
        'utc_time': str(datetime.utcnow().strftime("%Y/%m/%d %H:%M:%S")),
        'time': str(datetime.now().strftime("%Y/%m/%d %H:%M:%S"))
    }
    return res

@app.before_request
def before_request():
    db.connect()

@app.after_request
def after_request(response):
    db.close()
    return response

@app.errorhandler(404)
@as_json
def not_found(error):
    res = {
        'code': 404,
        'msg': "not found"
    }
    return res