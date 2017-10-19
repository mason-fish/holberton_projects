import math

''' Class for a Circle object '''
class Circle():
    def __init__(self, radius):
        self.__radius = radius
        self.name = ""

    def set_color(self, color):
        self.__color = color

    def get_color(self):
        return self.__color

    def set_center(self, center):
        self.__center = center

    def get_center(self):
        return self.__center

    def area(self):
        return (self.__radius ** 2) * math.pi

    def intersection(self, c_bis):
        c_rad = math.sqrt(c_bis.area() / math.pi)
        x2 = c_bis.get_center()[0]
        y2 = c_bis.get_center()[1]
        x1 = self.__center[0]
        y1 = self.__center[1]

        dist = math.sqrt(((x1 - x2) ** 2) + ((y1 - y2) ** 2))
        if (c_rad + self.__radius) >= dist:
            return True
        return False
