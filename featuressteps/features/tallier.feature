Feature: The Tallier
	Values are entered for weight and points
	Valid values are calculated into a result
	
Scenario:
	Given I have compiled the program
	When I execute it with "5"
	And I execute it with "10"
	Then output should be "This transaction has earned 346.140533 points."