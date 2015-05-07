 def command_output_to_s(system_command)
      IO.popen(system_command,:err=>[:child,:out]).read.gsub(/\n/,' ').rstrip
    end
	
Given /^I have compiled the program$/ do
      command_output_to_s('gcc -o r receipt_printer.c').should be_empty
      command_output_to_s('ls| grep receipt_printer').should eq("receipt_printer receipt_printer.c")
 end
 
When /^I execute it with "(.*?)"$/ do |arguments|
      @result = command_output_to_s('./receipt_printer ' + arguments)
end

Then /^the output should be "(.*?)"$/ do |text|
       @result.should eq(text)
end
