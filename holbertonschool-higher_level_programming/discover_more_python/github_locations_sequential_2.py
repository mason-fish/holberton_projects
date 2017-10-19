import json
import urllib
import urllib2
import time

def grabUrl (url, head):
    req = urllib2.Request(url, headers=head)
    res = urllib2.urlopen(req)
    ans = json.load(res)

    return ans

def main():

    head = {
        'User-Agent': 'Holberton_school',
        'Authorization': 'token 1b97b1e74f551c675ad4bd92b6c327bd0fe2253d'
    }

    url = 'https://api.github.com/search/repositories?q=language:python&sort=stars&order=desc'



    ans = grabUrl(url, head)
    full_result = []

    for d in ans["items"]:
        new_Res = grabUrl('https://api.github.com/users/' + d["owner"]["login"], head)

        obj = {
            "full_name": d["full_name"],
            "location": new_Res["location"]
        }

        full_result.append(obj)

    print json.dumps(full_result, sort_keys=True)

main()
