#!/usr/bin/ruby
require "yaml"
require "optparse"
require "aws-sdk"


config = YAML.load_file('config.yaml')
supportedActions = ["launch", "start", "stop", "terminate"]

options = {}
OptionParser.new do |opts|
  opts.banner = "Usage: 0-manage_ec2_instances.rb [options]"

  opts.on("-v", "--[no-]verbose", "Run verbosely") do |v|
    options[:verbose] = v
  end

  opts.on("-a MANDATORY", "--action=MANDATORY", "Run action against AWS API") do |a|
    if supportedActions.include? a
      options[:action] = a
    else
      puts "Provided action does not exist"
    end
  end

  opts.on("-i MANDATORY", "--instance_id=MANDATORY", "AWS instance to target") do |i|
    options[:instance_id] = i
  end
  
end.parse!

if supportedActions.include? options[:action]
    Aws.config.update({
                      region: config['availability-zone'],
                      credentials: Aws::Credentials.new(config['access_key_id'], config['secret_access_key'])
                    })
  
  s3 = Aws::EC2::Client.new()
end

# ACTION: launch
if options[:action] == "launch"
  res = s3.run_instances({
                               image_id: config['image_id'],
                               key_name: config['key_pair'],
                               min_count: 1,
                               max_count: 1,
                               instance_type: config['instance_type'],
                               security_group_ids: config['security_group_ids']
                         })

  id = res.instances[0].instance_id
  statusResponse = s3.describe_instances({
                                                 instance_ids: [id]
                                         })
  status = statusResponse.reservations[0].instances[0].state.name

  if options[:verbose]
    puts "Launching machine..."
  end
 
  while status != "running"
    sleep 1
    if options[:verbose]
      puts "..."
    end
      statusResponse = s3.describe_instances({
                                               instance_ids: [id]
                                             })
      status = statusResponse.reservations[0].instances[0].state.name
  end

  if options[:verbose]
    puts "Machine launched, and running!"
    puts "Instance ID: ", id
    puts "Instance public DNS: ", statusResponse.reservations[0].instances[0].public_dns_name
  else
    puts id, statusResponse.reservations[0].instances[0].public_dns_name
  end


# ACTION: start
elsif options[:action] == "start" and options.key?(:instance_id)
  res = s3.start_instances({
                                  instance_ids: [options[:instance_id]],
                                })
  statusResponse = s3.describe_instances({
                                           instance_ids: [options[:instance_id]]
                                         })
  status = statusResponse.reservations[0].instances[0].state.name
  if options[:verbose]
    puts "Starting machine..."
  end
  while status != "running"
    sleep 1
    if options[:verbose]
      puts "..."
    end
      statusResponse = s3.describe_instances({
                                               instance_ids: [options[:instance_id]]
                                             })
      status = statusResponse.reservations[0].instances[0].state.name
  end
  if options[:verbose]
    puts "Machine has been started!"
    puts "Instance public DNS: ", statusResponse.reservations[0].instances[0].public_dns_name
  else
    puts statusResponse.reservations[0].instances[0].public_dns_name
  end


# ACTION: stop
elsif options[:action] == "stop" and options.key?(:instance_id)
  res = s3.stop_instances({
                                  instance_ids: [options[:instance_id]],
                              })

  statusResponse = s3.describe_instances({
                                           instance_ids: [options[:instance_id]]
                                         })
  status = statusResponse.reservations[0].instances[0].state.name
  if options[:verbose]
    puts "Stopping machine..."
  end
  while status != "stopped"
    sleep 1
    if options[:verbose]
      puts "..."
    end
    statusResponse = s3.describe_instances({
                                             instance_ids: [options[:instance_id]]
                                           })
    status = statusResponse.reservations[0].instances[0].state.name
  end
  if options[:verbose]
    puts "Machine has been stopped!"
  end


# ACTION: terminate
elsif options[:action] == "terminate" and options.key?(:instance_id)
  res = s3.terminate_instances({
                                 instance_ids: [options[:instance_id]]
                               })

  statusResponse = s3.describe_instances({
                                           instance_ids: [options[:instance_id]]
                                         })
  status = statusResponse.reservations[0].instances[0].state.name
  if options[:verbose]
    puts "Terminating machine..."
    while status != "terminated"
      sleep 1
      if options[:verbose]
        puts "..."
      end
      statusResponse = s3.describe_instances({
                                               instance_ids: [options[:instance_id]]
                                             })
      status = statusResponse.reservations[0].instances[0].state.name
    end
    puts "Machine has been terminated!"
  end
  
end
