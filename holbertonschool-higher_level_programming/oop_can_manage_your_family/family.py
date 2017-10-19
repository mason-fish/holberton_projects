import time
from datetime import date
import os.path
import json

''' save_to_file() saves a Person list as a JSON to file '''
def save_to_file(list, filename):
    if not os.path.isfile(filename) or type(filename) is not str:
        raise Exception("filename is not valid or doesn't exist")

    f = open(filename, 'w')
    full = []
    for i in list:
        j = i.json()
        j['kind'] = type(i).__name__
        full.append(j)

    f.write(json.dumps(full))
    f.close()

def load_from_file(filename):
    if not os.path.isfile(filename):
        raise Exception("filename is not valid or doesn't exist")

    f = open(filename, 'r')
    full = f.read()
    f.close

    my_list = []
    for i in json.loads(full):
        y = eval(i['kind'])(0, "okay", [1,1,1], "Female", "Green")
        y.load_from_json(i)
        my_list.append(y)

    return my_list



''' The Person class defines the Person object '''
class Person(object):

    ''' Class attributes '''
    EYES_COLORS = ["Blue", "Green", "Brown"]
    GENRES = ["Female", "Male"]

    ''' Constructor, for object initialization '''
    def __init__(self, id, first_name, date_of_birth, genre, eyes_color):

        if type(id) is not int or id < 0:
            raise Exception("id is not an integer")

        if type(first_name) is not str:
            raise Exception("first_name is not a string")

        assert type(date_of_birth) is list
        for i in date_of_birth:
            if type(i) is not int:
                raise Exception("date_of_birth is not a valid date")
        if 1 > date_of_birth[0] > 31:
                raise Exception("date_of_birth is not a valid date")
        if 1 > date_of_birth[1] > 12:
                raise Exception("date_of_birth is not a valid date")

        if type(genre) is not str or genre not in Person.GENRES:
            raise Exception("genre is not valid")

        if type(eyes_color) is not str or eyes_color not in Person.EYES_COLORS:
            raise Exception("eyes_color is not valid")

        ''' private attributes (after validation) '''
        self.__genre = genre
        self.__eyes_color = eyes_color
        self.__date_of_birth = date_of_birth
        self.__id = id
        self.__first_name = first_name

        ''' public attributes '''
        self.last_name = ""
        self.is_married_to = 0
        self.children = []

    ''' modify the comparator of a Person to represent age '''
    def __cmp__(self, right):
        return cmp(self.age(), right.age())

    ''' modify the string representation of a Person to be the first and last name '''
    def __str__(self):
        return self.__first_name + " " + self.last_name

    ''' get_id() returns the __id of a Person '''
    def get_id(self):
        return self.__id

    ''' get_first_name() returns the first name of a Person '''
    def get_first_name(self):
        return self.__first_name

    ''' get_date_of_birth() returns an array of ints representing
        the date of birth of a Person '''
    def get_date_of_birth(self):
        return self.__date_of_birth

    ''' get_genre() returns the gender of a Person '''
    def get_genre(self):
        return self.__genre

    ''' get_eyes_color() returns the __eyes_color attribute of a Person '''
    def get_eyes_color(self):
        return self.__eyes_color

    ''' is_male() returns True if a Person is a Male, False otherwise '''
    def is_male(self):
        return (self.__genre == "Male")

    ''' age() returns the age, in years, of a Person '''
    def age(self):
        dob = date(self.__date_of_birth[2], self.__date_of_birth[0], self.__date_of_birth[1])
        day = date(2016, 5, 20)
        age = day - dob
        return abs(age.days / 365)

    ''' json() returns a dict of attributes from a Person '''
    def json(self):
        return {
        'id': self.get_id(),
        'eyes_color': self.get_eyes_color(),
        'genre': self.get_genre(),
        'date_of_birth': self.get_date_of_birth(),
        'first_name': self.get_first_name(),
        'last_name': self.last_name,
        'is_married_to': self.is_married_to
        }

    ''' load_from_json() assigns Person attributes from a json dict '''
    def load_from_json(self, json):
        if type(json) is not dict:
            raise Exception("json is not a hash")

        ''' set private attributes '''
        self.__id = json['id']
        self.__first_name = json['first_name']
        self.__date_of_birth = json['date_of_birth']
        self.__genre = json['genre']
        self.__eyes_color = json['eyes_color']

        ''' set public attributes '''
        self.last_name = json['last_name']
        self.is_married_to = json['is_married_to']

class Baby(Person):
    def can_run(self):
        return False

    def need_help(self):
        return True

    def is_young(self):
        return True

    def can_vote(self):
        return False

    def can_be_married(self):
        return False

    def is_married(self):
        if self.is_married_to > 0:
            return True
        return False

    def divorce(self, p):
        self.is_married_to = 0
        p.is_married_to = 0

    def just_married_with(self, p):
        if self.can_be_married() is not True or p.can_be_married() is not True:
            raise Exception("Can't be married")
        if self.is_married() is True or p.is_married() is True:
            raise Exception("Already married")

        self.is_married_to = p.get_id()
        p.is_married_to = self.get_id()

        if self.get_genre() is "Female" and p.get_genre() is "Male":
            self.last_name = p.last_name

        if p.get_genre() is "Female" and self.get_genre() is "Male":
            p.last_name = self.last_name

    def can_have_child(self):
        return False

    def has_child_with(self, p, id, first_name, date_of_birth, genre, eyes_color):
        if self.can_have_child() is False:
            raise Exception("Can't have a child")
        if p is None or p.can_have_child() is False:
            raise Exception("p can't have a child")

        new_born = Baby(id, first_name, date_of_birth, genre, eyes_color)
        self.children.append(new_born.get_id())
        p.children.append(new_born.get_id())
        return new_born

    def adopt_child(self, c):
        if self.can_have_child is False:
            raise Exception("Can't adopt a person")
        if c.can_vote() is True:
            raise Exception("c can't be adopted")

        self.children.append(c.get_id())

class Teenager(Person):
    def can_run(self):
        return True

    def need_help(self):
        return False

    def is_young(self):
        return True

    def can_vote(self):
        return False

    def can_be_married(self):
        return False

    def is_married(self):
        if self.is_married_to > 0:
            return True
        return False

    def divorce(self, p):
        self.is_married_to = 0
        p.is_married_to = 0

    def just_married_with(self, p):
        if self.can_be_married() is not True or p.can_be_married() is not True:
            raise Exception("Can't be married")
        if self.is_married() is True or p.is_married() is True:
            raise Exception("Already married")

        self.is_married_to = p.get_id()
        p.is_married_to = self.get_id()

        if self.get_genre() is "Female" and p.get_genre() is "Male":
            self.last_name = p.last_name

        if p.get_genre() is "Female" and self.get_genre() is "Male":
            p.last_name = self.last_name

    def can_have_child(self):
        return False

    def has_child_with(self, p, id, first_name, date_of_birth, genre, eyes_color):
        if self.can_have_child() is False:
            raise Exception("Can't have a child")
        if p is None or p.can_have_child() is False:
            raise Exception("p can't have a child")

        new_born = Baby(id, first_name, date_of_birth, genre, eyes_color)
        self.children.append(new_born.get_id())
        p.children.append(new_born.get_id())
        return new_born

    def adopt_child(self, c):
        if self.can_have_child is False:
            raise Exception("Can't adopt a person")
        if c.can_vote() is True:
            raise Exception("c can't be adopted")

        self.children.append(c.get_id())


class Adult(Person):
    def can_run(self):
        return True

    def need_help(self):
        return False

    def is_young(self):
        return False

    def can_vote(self):
        return True

    def can_be_married(self):
        return True

    def is_married(self):
        if self.is_married_to > 0:
            return True
        return False

    def divorce(self, p):
        self.is_married_to = 0
        p.is_married_to = 0

    def just_married_with(self, p):
        if self.can_be_married() is not True or p.can_be_married() is not True:
            raise Exception("Can't be married")
        if self.is_married() is True or p.is_married() is True:
            raise Exception("Already married")

        self.is_married_to = p.get_id()
        p.is_married_to = self.get_id()

        if self.get_genre() is "Female" and p.get_genre() is "Male":
            self.last_name = p.last_name

        if p.get_genre() is "Female" and self.get_genre() is "Male":
            p.last_name = self.last_name

    def can_have_child(self):
        return True

    def has_child_with(self, p, id, first_name, date_of_birth, genre, eyes_color):
        if self.can_have_child() is False:
            raise Exception("Can't have a child")
        if p is None or p.can_have_child() is False:
            raise Exception("p can't have a child")

        new_born = Baby(id, first_name, date_of_birth, genre, eyes_color)
        self.children.append(new_born.get_id())
        p.children.append(new_born.get_id())
        return new_born

    def adopt_child(self, c):
        if self.can_have_child is False:
            raise Exception("Can't adopt a person")
        if c.can_vote() is True:
            raise Exception("c can't be adopted")

        self.children.append(c.get_id())


class Senior(Person):
    def can_run(self):
        return False

    def need_help(self):
        return True

    def is_young(self):
        return False

    def can_vote(self):
        return True

    def can_be_married(self):
        return True

    def is_married(self):
        if self.is_married_to > 0:
            return True
        return False

    def divorce(self, p):
        self.is_married_to = 0
        p.is_married_to = 0

    def just_married_with(self, p):
        if self.can_be_married() is not True or p.can_be_married() is not True:
            raise Exception("Can't be married")
        if self.is_married() is True or p.is_married() is True:
            raise Exception("Already married")

        self.is_married_to = p.get_id()
        p.is_married_to = self.get_id()

        if self.get_genre() is "Female" and p.get_genre() is "Male":
            self.last_name = p.last_name

        if p.get_genre() is "Female" and self.get_genre() is "Male":
            p.last_name = self.last_name

    def can_have_child(self):
        return False

    def has_child_with(self, p, id, first_name, date_of_birth, genre, eyes_color):
        if self.can_have_child() is False:
            raise Exception("Can't have a child")
        if p is None or p.can_have_child() is False:
            raise Exception("p can't have a child")

        new_born = Baby(id, first_name, date_of_birth, genre, eyes_color)
        self.children.append(new_born.get_id())
        p.children.append(new_born.get_id())
        return new_born

    def adopt_child(self, c):
        if self.can_have_child is False:
            raise Exception("Can't adopt a person")
        if c.can_vote() is True:
            raise Exception("c can't be adopted")

        self.children.append(c.get_id())
