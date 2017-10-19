''' Class for defining a number and operations '''
class Number():
    def __init__(self, n):
        if type(n) is not int:
            return "Number takes an integer"
        self.__n = n

    def set_value(self, n):
        if type(n) is not int:
            return "Number takes an integer"
        self.__n = n

    def get_value(self):
        return self.__n

    def __str__(self):
        return str(self.__n)

    def __add__(self, n):
        x = n.get_value()
        return self.__n + x

    def __sub__(self, n):
        x = n.get_value()
        return self.__n - x

    def __div__(self, n):
        x = n.get_value()
        return self.__n / x

    def __mul__(self, n):
        x = n.get_value()
        return self.__n * x
