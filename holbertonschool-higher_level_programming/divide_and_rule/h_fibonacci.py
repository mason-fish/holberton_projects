'''
the fibonacci sequence using puthon threading
'''

import threading

class FibonacciThread(threading.Thread):
    def __init__(self, number):
        threading.Thread.__init__(self)
        if type(number) is not int:
            raise Exception("number is not an integer")
        self.number = number

    def fibonacci_term(self, x):
        if x < 2:
            return x

        return self.fibonacci_term(x - 1) + self.fibonacci_term(x - 2)

    def run(self):
        print("%d => %d") % (self.number, self.fibonacci_term(self.number))
