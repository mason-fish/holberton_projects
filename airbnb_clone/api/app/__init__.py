from flask import Flask
from flask_json import FlaskJSON
from flask_cors import CORS
from config import *
from api_logging import logger, setup_logging

app = Flask(__name__)
json = FlaskJSON(app)
cors = CORS(app, origins=CORS_CONFIG)

setup_logging()
#logger.error('LOG_TEST')

from app.views import *
