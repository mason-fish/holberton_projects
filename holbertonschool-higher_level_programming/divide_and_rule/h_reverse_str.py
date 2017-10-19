import threading

class ReverseStrThread(threading.Thread):
    def __init__(self, word):
        threading.Thread.__init__(self)
        if type(word) is not str:
            raise Exception("word is not a string")
        
        self.word = word
    
    sentence = ""

    def run(self):
        ReverseStrThread.sentence += self.word[::-1] + " "
