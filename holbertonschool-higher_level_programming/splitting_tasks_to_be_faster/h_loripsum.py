from threading import Thread, Lock
import requests

lock = Lock()

'''
This class defines a thread object which
requests a single random short paragraph of
lorem ipsum and writes this to a given file
'''
class LoripsumThread(Thread):
    def __init__(self, filename):
        Thread.__init__(self)
        self.filename = filename

    def run(self):
        with lock:
            file = open(self.filename, "a")
            url = "http://loripsum.net/api/1/short"
            res = requests.get(url)
            file.write(res.content)
            file.close
