import os

airbnb_env = os.environ.get('AIRBNB_ENV')

DATABASE = {
    'host': "158.69.92.181",
    'port': 3306,
    'charset': "utf8",
}

if airbnb_env == "development":
    CORS_CONFIG = ['*']
    DEBUG = True
    HOST = "localhost"
    PORT = 3333
    DATABASE['user'] = "airbnb_user_dev"
    DATABASE['database'] = "airbnb_dev"
    DATABASE['password'] = os.environ.get('AIRBNB_DATABASE_PWD_DEV')

elif airbnb_env == "production":
    CORS_CONFIG = ['127.0.0.1', '158.69.92.181']
    DEBUG = False
    HOST = "0.0.0.0"
    PORT = 3000
    DATABASE['user'] = "airbnb_user_prod"
    DATABASE['database'] = "airbnb_prod"
    DATABASE['password'] = os.environ.get('AIRBNB_DATABASE_PWD_PROD')

elif airbnb_env == "test":
    CORS_CONFIG = ['*']    
    DEBUG = False
    HOST = "localhost"
    PORT = 5555
    DATABASE['user'] = "airbnb_user_test"
    DATABASE['database'] = "airbnb_test"
    DATABASE['password'] = os.environ.get('AIRBNB_DATABASE_PWD_TEST')
