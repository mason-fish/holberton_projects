#!/usr/bin/ruby
send = ARGV[0].scan(/(?<=\[from:)\+?\w+/).join
rec = ARGV[0].scan(/(?<=\[to:)\+?\w+/).join
flag = ARGV[0].scan(/(?<=\[flags:)[\-?\d\:]+/).join
puts send + "," + rec + "," + flag
