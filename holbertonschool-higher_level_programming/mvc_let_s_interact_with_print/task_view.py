''' view script '''

import Tkinter as tk

class TaskView(tk.Toplevel):

    def __init__(self, master):
        tk.Toplevel.__init__(self, master)
        self.protocol('WM_DELETE_WINDOW', self.master.destroy)

        if not isinstance(master, tk.Tk):
            raise Exception("master is not a tk.Tk()")

        ''' label widget for task display '''
        self.__title_var = tk.StringVar()
        self.__title_label = tk.Label(self, textvariable=self.__title_var)
        self.__title_label.pack(side="right")

        ''' reverse button to reverse label contents '''
        self.toggle_button = tk.Button(self, text="Reverse")
        self.toggle_button.pack(side="left")

    def update_title(self, title):
        if type(title) is not str:
            raise Exception("title is not a string")

        self.__title_var.set(title)
        self.__title_label.pack(side="right")
