from fabric.api import *
from fabric.operations import *

env.use_ssh_config = True
env.hosts = ['41_web_01', '41_web_02']

def deploy_mason():
    local('tar -X exclude.txt -czf api.tar.gz .')
    put('./api.tar.gz', '/tmp/')
    sudo('tar -xzf /tmp/api.tar.gz -C ~/api', shell=False)
    sudo('chown -R $AIRBNB_OWNER: ~/api', shell=False)
    run('rm -f /tmp/api.tar.gz')
    local('rm -f ./api.tar.gz')

def update_dependencies():
    sudo('pip install -r ~/api/requirements.txt', shell=False)

# def launch_api():
#     run('python ~/api/app.py')
