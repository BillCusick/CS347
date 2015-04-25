#include "ticket.h"

int main() {
	char printable[BUFFSIZE];
	char* pointMessage = "Point Value";
	int readReturn;
	int iterate;
	int innerate;
	int length;
	
	printf("%s \n", "Please enter a point value for testing");
	readReturn = read(0, printable, BUFFSIZE - 1);
	printable[readReturn - 1] = '\0';
			
	for(iterate = 0; iterate < 32; iterate++) {
		printf("%c", '*');
	}
	
	for(iterate = 0; iterate < 14; iterate++) {
		printf("%c", '*');
		for(innerate = 0; innerate < 30; innerate++) {
			printf("%c", ' ');
		}
		printf("%c\n", '*');
	}
	
	printf("%c", '*');
	for(innerate = 0; innerate < 9; innerate++) {
			printf("%c", ' ');
	}
	printf("%s", pointMessage);
	
	for(innerate = 0; innerate < 10; innerate++) {
			printf("%c", ' ');
	}
	printf("%c \n", '*');
	
	length = strlen(printable);
	if((length % 2) != 0) {
		length++;
	}
	
	length /= 2;
	
	if(length >= 13) {
		printf("%s", "Point value too high!");
	}
	else {
		printf("%c", '*');
		for(innerate = 0; innerate < (15 - length); innerate++) {
			printf("%c", ' ');
		}
	
		printf("%s", printable);
		
		for(innerate = 0; innerate < (15 - length); innerate++) {
			printf("%c", ' ');
		}
		printf("%c\n", '*');
		
		for(iterate = 0; iterate < 15; iterate++) {
			printf("%c", '*');
			for(innerate = 0; innerate < 30; innerate++) {
				printf("%c", ' ');
			}
			printf("%c\n", '*');
		}
		
		for(iterate = 0; iterate < 32; iterate++) {
			printf("%c", '*');
		}
	}
	printf("\n", ' ');
}