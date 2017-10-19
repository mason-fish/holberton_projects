import json
from xml.dom.minidom import Document

''' define a car class '''
class Car(object):

    def __init__(self, *args, **kwargs):
        if len(args) == 1 and type(args[0]) is str and len(args[0].split(",")) == 3:
            name, brand, nb_doors = args[0].split(",", 3)
            nb_doors = int(nb_doors)

        elif len(args) > 0 and isinstance(args[0], dict):
            new_hash = args[0]
            name = new_hash.get('name')
            brand = new_hash.get('brand')
            nb_doors = new_hash.get('nb_doors')
        else:
            name = kwargs.get('name')
            brand = kwargs.get('brand')
            nb_doors = kwargs.get('nb_doors')

        if name == None or not isinstance(name, str):
            raise Exception("name is not a string")
        if brand == None or not isinstance(brand, str):
            raise Exception("brand is not a string")
        if nb_doors == None or not isinstance(nb_doors, int) or nb_doors <= 0:
            raise Exception("nb_doors is not > 0")

        self.__name = name
        self.__brand = brand
        self.__nb_doors = nb_doors

    def __str__(self):
        return self.__name + " " + self.__brand + " " + "(" + str(self.__nb_doors) + ")"

    def to_hash(self):
        return {
            'name': self.__name,
            'brand': self.__brand,
            'nb_doors': self.__nb_doors
            }

    def get_name(self):
        return self.__name

    def get_brand(self):
        return self.__brand

    def get_nb_doors(self):
        return self.__nb_doors

    def set_nb_doors(self, number):
        if not isinstance(number, int) or number <= 0:
            raise Exception("nb_doors is not > 0")
        self.__nb_doors = number

    def to_json_string(self):
        return json.dumps(self.to_hash())

    def to_xml_node(self, doc):
        car = doc.createElement('car')
        car.setAttribute('nb_doors', str(self.__nb_doors))

        name = doc.createElement('name')
        name_content = doc.createCDATASection(self.__name)
        name.appendChild(name_content)
        car.appendChild(name)

        brand = doc.createElement('brand')
        brand_content = doc.createTextNode(self.__brand)
        brand.appendChild(brand_content)
        car.appendChild(brand)

        return car

    def to_comma(self):
        tup = (self.__name, self.__brand, str(self.__nb_doors))
        return ",".join(tup) + "\n"
