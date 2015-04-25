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
	
	for(iterate = 0; iterate < 60; iterate++) {
		ticketColors[iterate] = "n";
		ticketPoints[iterate] = 0;
	}
	/*
	Presenting the users with instructions that they'll need
	*/
	printf("%s\n", "Welcome to the Worker Interface. Here are the commands:");
	printf("%s\n", "'Exit' to leave the program.");
	printf("%s\n", "'Set:' followed by 'color,number' to set a value");
	printf("%s\n", "'Delete:' followed by 'color' to remove a value");
	
	while(1) {
		printf("%s\n", "Please enter input");
		
		readReturn = read(0, input, BUFFSIZE - 1);
		input[readReturn] = '\0';
		
		//printf("%i \n", strncmp(input, "set", 3));
		/*
		Execute this case when user is trying to exit.
		*/
		if(0 == strncmp(input, "\E", 1) || 0 == strncmp(input, "Exit", 4) || 0 == strncmp(input, "exit", 4)) {
			printf("%s \n", "Exiting Worker Interface...");
			exit(0);
		}
		/*
		Execute this case when user is trying to assign a new color/value pair
		*/
		else if(0 == strncmp(input, "Set", 3) || 0 == strncmp(input, "set", 3)) {
			/*
			Prompt the user for the color,value pair desired
			*/
			printf("%s \n", "Please enter a ticket color and point value in the form color,value");
			printf("%s \n", "To cancel this operation, enter 'Cancel'");
			/*
			Getting values from the user
			*/
			readReturn = read(0, input, BUFFSIZE - 1);
			input[readReturn] = '\0';
			/*
			If the user wants to cancel the operation, do nothing.
			*/
			if(0 == strncmp(input, "Cancel", 6) || 0 == strncmp(input, "cancel", 6)) {
				printf("%s \n", "Cancelling...");
			}
			/*
			Otherwise, parse the user's input and try to store the color value pair
			*/
			else if(arrayLocation > 59) {
				printf("%s \n", "The database is full. Please delete items.");
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
					printf("%s \n", "Improperly formatted input.");
				}
				else if(iterate > 1023) {
					printf("%s \n", "The color name is too long.");
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
					for(; input[iterate] != '\0' && input[iterate] >= '0' && input[iterate] <= '9'; iterate++) {
						value *= 10;
						value += (int)(input[iterate] - '0');
					}
					//printf("%s \n", "Got Here4");
					if(input[iterate] <= '0' && input[iterate] >= '9') {
						printf("%s \n", "The value of the color was not entered as an integer.");
					}
					else {
						ticketColors[arrayLocation] = strdup(&color[0]);
						//printf("%s \n", "Got Here5.7");
						ticketPoints[arrayLocation] = value;
						arrayLocation++; //Need to replace this with freeSeek(), to get lowest available index each time.
						printf("%s", "The value pair ");
						printf("%s", &color[0]);
						printf("%s", ", ");
						printf("%i", value);
						printf("%s \n", " has been stored.");
						//printf("%s \n", "Got Here7");
					}
				}
			}
		}
		/*
		Execute this case when user is trying to delete a color/value pair
		*/
		else if(0 == strncmp(input, "Delete", 6) || 0 == strncmp(input, "delete", 6)) {
			printf("%s \n", "Please specify a color to delete.");
			readReturn = read(0, input, BUFFSIZE - 1);
			input[readReturn] = '\0';
			for(iterate = 0; iterate < 60; iterate++) {
				if(strcmp(ticketColors[iterate], input) == 0) {
					printf("%s \n", "Deleted the color from database.");
					arrayLocation = iterate;
					break;
				}
			}
			
		}
		else {
			printf("%s \n", "Command not recognized");
		}
	}
}