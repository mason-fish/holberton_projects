import os

airbnb_env = os.environ.get('AIRBNB_ENV')

if airbnb_env == "development":
    PORT = 3333
    errorlog = '-'
    accesslog = '-'

elif airbnb_env == "production":
    PORT = 3000
    errorlog = '/var/log/airbnb_api/error.log'
    accesslog = '/var/log/airbnb_api/access.log'

elif airbnb_env == "test":
    PORT = 5555
    errorlog = '-'
    accesslog = '-'


bind = "0.0.0.0:" + str(PORT)
reload = True
