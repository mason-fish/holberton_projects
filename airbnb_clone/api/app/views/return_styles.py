from flask_json import jsonify
from app.models import *
from peewee import *

class ListStyles():
    @staticmethod
    def list(select, request):
        styled_return = {
            'data': "No results",
            'paging': {
                'next': None,
                'previous': None
            }
        }

        page = 1
        num = 10
        
        if request.args.get('page'):
            page = int(request.args.get('page'))
        if request.args.get('number'):
            num = int(request.args.get('number'))
        
        total = len([r for r in select])
        styled_return['data'] = [r.to_dict() for r in select.paginate(page, num)]
        
        if page > 1:
            styled_return['paging']['previous'] = request.base_url + "?page=" + str(page - 1) + "&number=" + str(num) 
        if page * num < total:
            styled_return['paging']['next'] = request.base_url + "?page=" + str(page + 1) + "&number=" + str(num)

        return jsonify(styled_return)