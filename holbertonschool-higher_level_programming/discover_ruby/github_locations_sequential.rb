require 'HTTPClient'
require 'json'

extheaders = {
  'User-Agent' => 'Holberton_School',
  'Authorization' => 'token 1b97b1e74f551c675ad4bd92b6c327bd0fe2253d'
}

uri = 'https://api.github.com/search/repositories?q=language:ruby&sort=stars&order=desc'

clnt = HTTPClient.new
res = JSON.parse(clnt.get_content(uri, extheaders))

full_res = []
res["items"].map do |var|
  item_res = JSON.parse(clnt.get_content(var["owner"]["url"], "q=language:ruby", extheaders))
  item_next = {
    "full_name" => var["full_name"],
    "location" => item_res["location"]
  }
  full_res.push(item_next)
end

puts full_res.to_json
