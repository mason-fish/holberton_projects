require 'HTTPClient'
require 'json'

extheaders = {
  'User-Agent' => 'Holberton_School',
  'Authorization' => 'token 9f64412d7bbda257edb5a3c976db2379a43486f5'
}

uri = 'https://api.github.com/search/repositories?q=language:ruby&sort=stars&order=desc'

clnt = HTTPClient.new
res = JSON.parse(clnt.get_content(uri, extheaders))

full_res = []
req_arr = []
res["items"].map do |var|
  req_arr << Thread.new(var["owner"]["url"], extheaders) do |a, b|
    item_res = JSON.parse(clnt.get_content(a, "q=language:ruby", b))
    item_next = {
      "full_name" => var["full_name"],
      "location" => item_res["location"]
    }
    full_res.push(item_next)
  end
end

req_arr.each { |x| x.join }
puts full_res.to_json
