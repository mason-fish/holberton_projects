import json
import urllib
import urllib2

head = {
    'User-Agent': 'Holberton_school',
    'Authorization': 'token 1b97b1e74f551c675ad4bd92b6c327bd0fe2253d'
}

url = 'https://api.github.com/search/repositories?q=language:python&sort=stars&order=desc'

req = urllib2.Request(url, headers=head)
res = urllib2.urlopen(req)
ans = res.read()

print(ans)
