#include "ticket.h"

/*
tallier.c
Author: William Cusick
I pledge my honor that I have abided by the Stevens Honor System
*/

int main() {
	char input[BUFFSIZE];
	/*
	Weight is measured in total here, and a running
	tally is what this variable measures. The bin needs
	to zero out each time to get an accurate value, because
	that's how scales work. 
	*/
	static double totalBinWeight = 0;
	/*
	The maximum weight the bin can report before it errors
	out. This is about how much I'd expect someone to be able
	to carry around, in grams. Almost exactly 40 lbs.
	*/
	const double maxBinWeight = 18145;
	/*
	This is the weight of a tiny piece of paper. 
	*/
	const double ticketWeight = .14445;
	double binWeight;
	int readReturn;
	double pointValue;
	double ticketNumber;
	
	
	while(1) {
		
		if(totalBinWeight > maxBinWeight) {
			printf("%s \n", "Please replace bin");
			break;
		}
		else {
			printf("%s \n", "Please enter a point value");
			
			readReturn = read(0, input, BUFFSIZE - 1);
			input[readReturn] = '\0';
			
			pointValue = atoi(input);
			
			if(pointValue > 0) {
				printf("%s \n", "Please enter a bin weight");
			
				readReturn = read(0, input, BUFFSIZE - 1);
				input[readReturn] = '\0';
				
				binWeight = atof(input);
				
				if(binWeight > 0) {
					ticketNumber = binWeight / ticketWeight;
					totalBinWeight += binWeight;
					floor(ticketNumber);
					pointValue = ticketNumber * pointValue;
					printf("%s", "This transaction has earned ");
					printf("%f", pointValue);
					printf("%s \n", " points.");
				}
				else {
					printf("%s \n", "Invalid bin weight entered");
				}
			}
			else {
				printf("%s \n", "Invalid point value entered");
			}
		}
	}
}