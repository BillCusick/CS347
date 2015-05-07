Feature: Printing The Receipt
	A value is entered for testing
	If it's valid it is printed with a template
	
Scenario:
	Given I have compiled the program
	When I execute it with "7"
	Then output should be
	"""
	*********************************                              
	*                              *
	*                              *
	*                              *
	*                              *
	*                              *
	*                              *
	*                              *
	*                              *
	*                              *
	*                              *
	*                              *
	*                              *
	*                              *
	*         Point Value          *
	*              50              *
	*                              *
	*                              *
	*                              *
	*                              *
	*                              *
	*                              *
	*                              *
	*                              *
	*                              *
	*                              *
	*                              *
	*                              *
	*                              *
	*                              *
	*                              *
	********************************
	"""