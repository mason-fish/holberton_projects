import threading

class OrderedArray(object):
    list = []

    def __init__(self):
        pass

    def add(self, number):
        if type(number) is not int:
            raise Exception("number is not an integer")
        
        insert_thread = OrderedArrayThread(number)
        insert_thread.start()

    def isSorting(self):
        if OrderedArrayThread.threads > 1:
            return True
        else:
            return False
            
        
    def __str__(self):
        return '[%s]' % ', '.join(map(str, OrderedArray.list))
        
class OrderedArrayThread(threading.Thread):
        threads = 0
        
        def __init__(self, number):
            threading.Thread.__init__(self)
            OrderedArrayThread.threads += 1
            if type(number) is not int:
                raise Exception("number is not an integer")
            
            self.number = number
        
        def run(self):
            ndx = 0
            while ndx < len(OrderedArray.list) and self.number > OrderedArray.list[ndx]:
                ndx += 1
            OrderedArray.list.insert(ndx, self.number)
            OrderedArrayThread.threads -= 1
            
        