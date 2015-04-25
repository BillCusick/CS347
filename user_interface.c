#include "ticket.h"

int main() {
	/*
	Ideally, this code would read in a while loop from some
	other process, like tallier, and print the point value 
	every time. 
	*/
	char readable[BUFFSIZE];
	int readReturn;
	char* userMessage = "Your Current Points:";
	int iterate;
	int length;
	
	printf("%s \n", "Please enter a point value, for testing");
	readReturn = read(0,readable, BUFFSIZE);
	readable[readReturn - 1] = '\0';
	
	for(iterate = 0; iterate < 31; iterate++) {
		printf("%c", '*');
	}
	printf("%c\n", '*');
	
	printf("%c", '*');
	for(iterate = 0; iterate < 5; iterate++) {
			printf("%c", ' ');
	}
	
	printf("%s", userMessage);
	
	for(iterate = 0; iterate < 5; iterate++) {
		printf("%c", ' ');
	}
	printf("%c \n", '*');
	
	length = strlen(readable);
	if((length % 2) != 0) {
		length++;
	}
	
	length /= 2;
	
	if(length >= 13) {
		printf("%s", "Point value too high!");
	}
	else {
		printf("%c", '*');
		for(iterate = 0; iterate < (15 - length); iterate++) {
			printf("%c", ' ');
		}
	
		printf("%s", readable);
		
		for(iterate = 0; iterate < (15 - length); iterate++) {
			printf("%c", ' ');
		}
		printf("%c\n", '*');
		
		for(iterate = 0; iterate < 31; iterate++) {
			printf("%c", '*');
		}
		printf("%c\n", '*');
	}
	
}