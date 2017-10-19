''' class to define Square objects '''

class Square():

    def __init__(self, side_length):
        if type(side_length) is not int:
            print "Please enter an integer for the length."

        self.__side_length = side_length

    def set_color(self, color):
        if type(color) is not str:
            self.__color = color

    def get_color(self):
        return self.__color

    def set_center(self, center):
        self.__center = center

    def get_center(self):
        return self.__center

    def area(self):
        return self.__side_length * self.__side_length

    def __str__(self):
        string = ""
        for i in range(0, self.__side_length):
            if i is not 0 and i is not self.__side_length - 1:
                string += "*" + (" " * (self.__side_length - 2)) + "*\n"
            else:
                string+= "*" * self.__side_length + "\n"

        return string
