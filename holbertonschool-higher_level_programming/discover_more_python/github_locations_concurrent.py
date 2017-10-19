import json
import urllib
import urllib2
import threading
import Queue

queue = Queue.Queue()
full_result = []

def grabUrl (url):
    head = {
        'User-Agent': 'Holberton_school',
        'Authorization': 'token 1b97b1e74f551c675ad4bd92b6c327bd0fe2253d'
    }

    req = urllib2.Request(url, headers=head)
    res = urllib2.urlopen(req)
    ans = json.load(res)

    return ans

class urlThread(threading.Thread):
    def __init__(self, queue):
        threading.Thread.__init__(self)
        self.queue = queue

    def run(self):
        while True:
            d = self.queue.get()
            new_Res = grabUrl('https://api.github.com/users/' + d["owner"]["login"])

            obj = {
                "full_name": d["full_name"],
                "location": new_Res["location"]
            }

            full_result.append(obj)
            self.queue.task_done()

def main():
    url = 'https://api.github.com/search/repositories?q=language:python&sort=stars&order=desc'

    ans = grabUrl(url)

    for d in ans["items"]:
        t = urlThread(queue)
        t.setDaemon(True)
        t.start()

        queue.put(d)

    queue.join()

    print json.dumps(full_result, sort_keys=True)

main()
