''' model script '''

class TaskModel(object):

    def __init__(self, title):
        if type(title) is not str:
            raise Exception("title is not a string")

        self.__title = title
        self.__callback_title = 0

    def __str__(self):
        return self.__title

    def get_title(self):
        return self.__title

    def set_callback_title(self, func):
        self.__callback_title = func

    def do_callback(self):
        if self.__callback_title:
            self.__callback_title(self.__title)

    def toggle(self):
        self.__title = self.__title[::-1]
        self.do_callback()

    def set_title(self, title):
        self.__title = title
        self.do_callback()



# def save_to_file(list, filename):
#     if not os.path.isfile(filename) or type(filename) is not str:
#         raise Exception("filename is not valid or doesn't exist")
#
#     f = open(filename, 'w')
#     full = []
#     for i in list:
#         j = i.json()
#         full.append(j)
#
#     f.write(json.dumps(full))
#     f.close()
#
#
