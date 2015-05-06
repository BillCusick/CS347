#include "ticket.h"

/*
find_open.c
Author: William Cusick
I pledge on my honor that I have abided by the Stevens Honor System
This function will just scroll through the array and find a suitable location
to store items in. On failure, returns -1.
*/

int find_open(int* colorArr) {
	int size;
	int iterate;
	size = sizeof(colorArr)/sizeof(colorArr[0]);
	
	for(iterate = 0; iterate < size; iterate++) {
		if(colorArr[iterate] == -1) {
			return iterate;
		}
	}
	
	return -1;
}