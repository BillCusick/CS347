Feature: Interface for Users
	A value is entered for testing
	If it's valid it is printed with a small template
	
Scenario:
	Given I have compiled the program
	When I execute it with "50"
	Then output should be
	"""
	********************************
	*     Your Current Points:     *
	*              4               *
	********************************
	"""