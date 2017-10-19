import logging
import logging.config
import os
import yaml

logger = logging.getLogger(__name__)

def setup_logging(
        default_path='logging.yaml',
        default_level=logging.INFO,
        env_key='AIRBNB_LOG'
):

#Setup logging configuration
    
    path = default_path
    value = os.getenv(env_key, None)
    if value:
        path = value
    
    if os.path.exists(path):
        with open(path, 'rt') as f:
            config = yaml.safe_load(f.read())
            logging.config.dictConfig(config)
    else:
        logging.basicConfig(level=default_level)
