from threading import Thread, BoundedSemaphore
from time import sleep
from random import randint

'''
Store defines a store object, including a customer capacity
as well as a simple single stock inventory
'''
class Store(object):
    def __init__(self, item_number, person_capacity):
        if type(item_number) is not int:
            raise Exception("item_number is not an integer")
        if type(person_capacity) is not int:
            raise Exception("person_capacity is not an integer")
        
        self.item_number = item_number
        self.person_capacity = person_capacity
        self.sema = BoundedSemaphore(value=self.person_capacity)

    def enter(self):
        self.sema.acquire()

    def buy(self):
        sleep(randint(5, 10))
        if self.item_number:
            purchase = True
            self.item_number -= 1
        else:
            purchase = False

        self.sema.release()
        return purchase