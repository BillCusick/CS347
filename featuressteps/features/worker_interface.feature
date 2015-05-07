Feature: Printing The Receipt
	A value is entered for testing
	If it's valid it is printed with a template
	
Scenario:
	Given I have compiled the program
	When I execute it with "set"
	And input is "blue, 42"
	Then output should be "The value pair blue, 42 has been stored."
	
Scenario:
	Given I have compiled the program
	When I execute it with "delete"
	And input is "red, 11"
	Then output should be "Error: Could not find specified color."

Scenario:
	Given I have compiled the program
	When I execute it with "exit"
	Then output should be "Exiting worker interface."
	