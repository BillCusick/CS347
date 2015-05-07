def command_output_to_s(system_command)
    IO.popen(system_command,:err=>[:child,:out]).read.gsub(/\n/,' ').rstrip
end
	
Given /^I have compiled the program$/ do
    command_output_to_s('gcc -o r worker_interface.c').should be_empty
    command_output_to_s('ls| grep worker_interface').should eq("worker_interface worker_interface.c")
end
 
When /^I execute it with "(.*?)"$/ do |arguments|
    @result = command_output_to_s('./worker_interface ' + arguments)
end

When /^input is "(.*)"$/ do |arguments|
    @input = arg
end

Then /^the output should be "(.*?)"$/ do |text|
    @result.should eq(text)
end