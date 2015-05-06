#include "ticket.h"

/*
find_color.c
Author: William Cusick
I pledge on my honor that I have abided by the Stevens Honor System
This function will just search through a character array for a string that matches
the first input.
*/

int find_color(char* color, char** colorArr) {
	int size, iterate;
	size = sizeof(colorArr)/sizeof(colorArr[0]);
	
	for(iterate = 0; iterate < size; iterate++) {
		if(strcmp(colorArr[iterate], color) == 0) {
			return iterate;
		}
	}
	
	return -1;
}