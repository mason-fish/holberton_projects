#!/usr/bin/ruby
webserver = {}
webserver['41-web-01'] = 0
webserver['41-web-02'] = 0
100.times do
  result=`curl -s http://52.91.146.225/loadbalancer.php`
  if result.include?('41-web-01')
    webserver['41-web-01'] += 1
  elsif result.include?('41-web-02')
    webserver['41-web-02'] += 1
  end
end

puts webserver.inspect
