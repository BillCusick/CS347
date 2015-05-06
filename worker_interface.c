#include "ticket.h"

/*
worker_interface.c
Author: William Cusick
I pledge my honor that I have abided by the Stevens Honor System
*/

int main() {
	/*
	So what this does. It allows one to set up the worker interface, 
	which will contain the value of the whatever. So if you enter
	"Set", enter a set mode, which prompts you for stuff and lets
	you enter a color, pointvalue. Searches point value array, 
	which can hold 60X2 items(2D array) and asks if you want to 
	either make a new entry or replace an existing one.
	If you enter "delete", it lets you enter a color and remove it
	from the 2D array. 
	*/
	
	char* ticketColors[60];
	int ticketPoints[60];
	int readReturn = 0;
	char** tC = &ticketColors[0];
	int* tP = &ticketPoints[0];
	int iterate = 0;
	char color[BUFFSIZE];
	int stringSize;
	int value;
	char input[BUFFSIZE];
	int arrayLocation = 0;
	int foundFlag = 0;
	
	for(iterate = 0; iterate < 60; iterate++) {
		ticketColors[iterate] = "n";
		ticketPoints[iterate] = -1;
	}
	/*
	Presenting the users with instructions that they'll need
	*/
	printf("%s\n", "Welcome to the Worker Interface. Here are the commands:");
	printf("%s\n", "'Exit' to leave the program.");
	printf("%s\n", "'Set' followed by 'color,number' to set a color-value pair");
	printf("%s\n", "'Delete' followed by 'color' to remove a value");
	printf("%s\n", "'Show' to display the current color-value pairs");
	printf("%s\n", "'Commands' to see this list reprinted");
	
	while(1) {
		printf("%s\n", "Please enter input");
		
		readReturn = read(0, input, BUFFSIZE - 1);
		//Changed this to test the enter shit being my strcmp problem
		input[readReturn - 1] = '\0';
		
		
		/*
		Execute this case when user is trying to exit.
		*/
		if(0 == strcmp(input, "\E") || 0 == strcmp(input, "Exit") || 0 == strcmp(input, "exit")) {
			printf("%s \n", "Exiting Worker Interface...");
			exit(0);
		}
		/*
		Execute this case when user is trying to assign a new color/value pair
		*/
		else if(0 == strcmp(input, "Set") || 0 == strcmp(input, "set")) {
			/*
			First, check if database has open spots.
			*/
			arrayLocation = find_open(ticketPoints);
						
			if(arrayLocation == -1) {
				printf("%s \n", "Error: The database is full. Please delete items.");
			}
						
			/*
			Prompt the user for the color,value pair desired
			*/
			printf("%s \n", "Please enter a ticket color and point value in the form color,value");
			printf("%s \n", "To cancel this operation, enter 'Cancel'");
			
			/*
			Getting values from the user
			*/
			readReturn = read(0, input, BUFFSIZE - 1);
			input[readReturn - 1] = '\0';
			
			/*
			If the user wants to cancel the operation, do nothing.
			*/
			if(0 == strcmp(input, "Cancel") || 0 == strcmp(input, "cancel")) {
				printf("%s \n", "Cancelling...");
			}
			
			else {
				stringSize = 0;
				/*
				Get the size of the bit
				*/
				for(iterate = 0; input[iterate] != '\0' && input[iterate] != ','; iterate++) {
					
				}
				//printf("%s \n", "Got Here1");
				/*
				Store the color portion of the input
				*/
				if(input[iterate] == '\0') {
					printf("%s \n", "Error: Improperly formatted input.");
				}
				else if(iterate > 1023) {
					printf("%s \n", "Error: The color name is too long.");
				}
				else {
					//printf("%s \n", "Got Here2");
					strncpy(&color[0], input, iterate);
					color[iterate] = '\0';
					
					//printf("%s \n", "Got Here3");
					/*
					Now, store the rest of the string as the value.
					Add one to iterate, so that it no longer points to the comma.
					*/
					iterate++;
					value = 0;
					for(; input[iterate] != '\0' || (input[iterate] >= '0' && input[iterate] <= '9') || input[iterate] == ' ' || input[iterate] == '\t'; iterate++) {
						if(!(input[iterate] == ' ' || input[iterate] == '\t')) {
							value *= 10;
							value += (int)(input[iterate] - '0');
						}
					}
					
					if(input[iterate] <= '0' && input[iterate] >= '9') {
						printf("%s \n", "Error: The value of the color was not entered as an integer.");
					}
					
					else {
						ticketColors[arrayLocation] = strdup(&color[0]);
						ticketPoints[arrayLocation] = value;
						
						printf("%s", "The value pair ");
						printf("%s", &color[0]);
						printf("%s", ", ");
						printf("%i", value);
						printf("%s \n", " has been stored.");
					}
				}
			}
		}
		
		/*
		Execute this case when user is trying to delete a color/value pair
		*/
		else if(0 == strcmp(input, "Delete") || 0 == strcmp(input, "delete")) {
			
			printf("%s \n", "Please specify a color to delete.");
			readReturn = read(0, input, BUFFSIZE - 1);
			input[readReturn - 1] = '\0';
			
			arrayLocation = find_color(input, ticketColors);
			
			if(arrayLocation == -1) {
				printf("%s \n", "Error: Could not find specified color.");
			}
			else {
				printf("%s", "The value pair ");
				printf("%s", input);
				printf("%s", ", ");
				printf("%i", ticketPoints[arrayLocation]);
				printf("%s \n", " has been deleted.");
				
				free(ticketColors[arrayLocation]);
				ticketColors[arrayLocation] = "n";
				ticketPoints[arrayLocation] = -1;
			}
		}
		
		/*
		Just reprinting the list of commands and how to use them again.
		*/
		else if(0 == strcmp(input, "Commands") || 0 == strcmp(input, "commands")) {
			printf("%s\n", "'Exit' to leave the program.");
			printf("%s\n", "'Set' followed by 'color,number' to set a color-value pair");
			printf("%s\n", "'Delete' followed by 'color' to remove a value");
			printf("%s\n", "'Show' to display the current color-value pairs");
			printf("%s\n", "'Commands' to see this list reprinted");
		}
		
		/*
		Showing the contents of the array
		*/
		else if(0 == strcmp(input, "Show") || 0 == strcmp(input, "show")) {
			foundFlag = 0;
			
			for(iterate = 0; iterate < 60; iterate++) {
				if(ticketPoints[iterate] != -1) {
					printf("%s", "The value pair ");
					printf("%s", ticketColors[iterate]);
					printf("%s", ", ");
					printf("%i", ticketPoints[iterate]);
					printf("%s \n", " is in the array");
					foundFlag = 1;
				}
			}
			if(!foundFlag) {
				printf("%s\n", "There are no values stored.");
			}
		}
		
		/*
		If this else is reached, the command wasn't recognized
		*/
		else {
			printf("%s \n", "Error: Command not recognized");
		}
	}
}