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

fd = open('6-main.json')
fd_contents = fd.read()
fd.close

fd_contents = json.loads(fd_contents)
fd_contents = byteify(fd_contents)

cars = []

for i in fd_contents:
    c = Car(i)
    cars.append(c.to_comma())

print "{0}".format("".join(cars))
