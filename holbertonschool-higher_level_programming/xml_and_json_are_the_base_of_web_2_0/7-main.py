from xml.dom.minidom import Document
from xml.sax.saxutils import unescape
from xml.dom import minidom
import json
from car import Car

''' Sweet little recursive function to convert unicode
keys and values from a list of dicts into utf-8 strings
Since the project specifies our functions check for str
(utf-8) I convert the json here. Otherwise could allow
in checking. Can also use yaml safe_load() since we know
all characters will be ASCII.
'''
def byteify(input):
    if isinstance(input, dict):
        return {byteify(key): byteify(value)
                for key, value in input.iteritems()}
    elif isinstance(input, list):
        return [byteify(element) for element in input]
    elif isinstance(input, unicode):
        return input.encode('utf-8')
    else:
        return input

fd = open('7-main.json')
fd_contents = fd.read()
fd.close

fd_contents = json.loads(fd_contents)
fd_contents = byteify(fd_contents)

cars = []
doc = Document()
cars_parent = doc.createElement('cars')
doc.appendChild(cars_parent)

for i in fd_contents:
    c = Car(i)
    cars.append(c)
    car_node = c.to_xml_node(doc)

    year = doc.createElement('year')
    year_content = doc.createTextNode('2015')
    year.appendChild(year_content)
    car_node.appendChild(year)

    car_node.setAttribute('weight', "1000")

    new_brand = doc.createElement('brand')
    brand_content = doc.createCDATASection(u"\u00a9" + str(c.get_brand()))
    new_brand.appendChild(brand_content)
    old_brand = car_node.getElementsByTagName('brand')
    car_node.replaceChild(new_brand, old_brand[0])

    cars_parent.appendChild(car_node)


print doc.toxml(encoding='utf-8')
