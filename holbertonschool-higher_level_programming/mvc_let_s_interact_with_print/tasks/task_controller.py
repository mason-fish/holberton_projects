''' controller script '''

import Tkinter as tk

from task_model import TaskModel
from task_view import TaskView

class TaskController(object):

    def __init__(self, master, models):
        if not isinstance(master, tk.Tk):
            raise Exception("master is not a tk.Tk()")
        for model in models:
            if not isinstance(model, TaskModel):
                raise Exception("model is not a TaskModel")

        self.__view = TaskView(master)

        self.__models = models
        # self.__view.update_title(self.__model.get_title())

        for model in self.models:
            model.set_callback_title(self.__view.update_model)

        self.__view.toggle_button.config(command=self.__model.toggle)

        self.__view.add_button.config(command=self.add_task)


    def add_task(self):
        task = self.__view.entry_input.get()
        if task != "Add a task here":
            new = TaskModel(task)
            self.__models.append(new)
            new.set_callback_title(self.__view.update_model)
