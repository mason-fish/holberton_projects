require 'HTTPClient'
require 'json'

extheaders = {
  'User-Agent' => 'Holberton_School',
  'Authorization' => 'token 1b97b1e74f551c675ad4bd92b6c327bd0fe2253d'
}

uri = 'https://api.github.com/search/repositories?q=language:ruby&sort=stars&order=desc'

clnt = HTTPClient.new
res = JSON.parse(clnt.get_content(uri, extheaders))

puts res["items"].map { |var| var["full_name"]}.join("\n")
