import Tkinter as tk

from task_model import TaskModel
from task_view import TaskView
from task_controller import TaskController

root = tk.Tk()
root.withdraw()

models = []
list = load_from_file("task_json.json")
for title in list:
    t = TaskModel(title)
    models.append(t)

tc = TaskController(root, models)
root.mainloop()

def load_from_file(filename):
    if not os.path.isfile(filename):
        raise Exception("filename is not valid or doesn't exist")

    f = open(filename, 'r')
    full = f.read()
    f.close

    my_list = []
    for i in json.loads(full):

        # y = eval(i['kind'])(0, "okay", [1,1,1], "Female", "Green")
        #y.load_from_json(i)
        print i
        my_list.append(i)

    print my_list
    return my_list
