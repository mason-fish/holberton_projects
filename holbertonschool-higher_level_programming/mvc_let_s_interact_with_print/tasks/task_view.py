''' view script '''

import Tkinter as tk

class TaskView(tk.Toplevel):

    def __init__(self, master):
        tk.Toplevel.__init__(self, master)
        self.protocol('WM_DELETE_WINDOW', self.master.destroy)

        if not isinstance(master, tk.Tk):
            raise Exception("master is not a tk.Tk()")

        ''' framing layout '''
        self.frame = tk.Frame(self)
        self.frame.pack()
        self.top_frame = tk.Frame(self.frame)
        self.top_frame.pack(side="top")

        ''' text entry widget to UI '''
        self.entry_input = tk.StringVar()
        self.task_entry = tk.Entry(self.top_frame, text=self.entry_input)
        self.task_entry.pack(side="left")
        self.entry_input.set("Add a task here")

        ''' button to add text entry as new task '''
        self.add_button = tk.Button(self.top_frame, text="Add task")
        self.add_button.pack(side="right")

        ''' label widget for task display '''
        count = g 
        self.__title_var = tk.StringVar()
        self.__title_label = tk.Label(self.frame, textvariable=self.__title_var)
        self.__title_label.pack(side="right")

        ''' reverse button to reverse label contents '''
        self.toggle_button = tk.Button(self.frame, text="Reverse")
        self.toggle_button.pack(side="left")

    def update_model(self, title):
        if type(title) is not str:
            raise Exception("title is not a string")

        self.__title_var.set(title)
