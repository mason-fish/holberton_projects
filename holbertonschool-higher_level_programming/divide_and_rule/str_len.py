import threading
import sys

class StrLenThread(threading.Thread):    
    def __init__(self, word):
        threading.Thread.__init__(self)
        if type(word) is not str:
            raise Exception("word is not a string")
        
        self.word = word

    def run(self):
        global total_str_length
        total_str_length += len(self.word)
        return total_str_length
        

total_str_length = 0
words = sys.argv[1].split(" ")
threads = []

for word in words:
    new_thread = StrLenThread(word)
    threads += [new_thread]
    new_thread.start()

for thread in threads:
    thread.join()

print total_str_length