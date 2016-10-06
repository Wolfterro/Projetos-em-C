/*
The MIT License (MIT)

Copyright (c) 2016 Wolfgang Almeida <wolfgang.almeida@yahoo.com>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

/* Required headers */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>

/* Defining possible colors for the wall */
#define RED       "\x1B[31m"
#define GREEN     "\x1B[32m"
#define YELLOW    "\x1B[33m"
#define BLUE      "\x1B[34m"
#define MAGENTA   "\x1B[35m"
#define CYAN      "\x1B[36m"
#define WHITE     "\x1B[37m"
#define RESET     "\x1B[0m"

/* Signal flag */
volatile sig_atomic_t f = 0;

/* Signal handler */
void endHandler(int sig) {
	f = 1;
}

/* Shows how much you've built when you exit the program */
void builtSoFar(long double meters) {
	printf(RESET "\nYou've built %.2Lf meters!\n", meters / 10);
	f = 0;
	exit(0);
}

/* Make Programming Great Again */
void buildingWall(int cc) {
	long double meters = 0.0;
	char color[12];
	
	switch(cc) {
		case 1:
			strcpy(color, RED);
			break;
		case 2:
			strcpy(color, GREEN);
			break;
		case 3:
			strcpy(color, YELLOW);
			break;
		case 4:
			strcpy(color, BLUE);
			break;
		case 5:
			strcpy(color, MAGENTA);
			break;
		case 6:
			strcpy(color, CYAN);
			break;
		case 7:
			strcpy(color, WHITE);
			break;
		default:
			strcpy(color, RESET);
			break;
	}
	
	signal(SIGINT, endHandler);
	printf("Building wall (press CTRL + C to stop)...\n");
	usleep(1000000);
	
	while(1) {
		if(f) {
			builtSoFar(meters);
		}
		
		printf("%s|¯¯¯¯", color);
		fflush(stdout);
		usleep(80000);
		meters += 0.2;
	}
}

/* Help menu */
void helpMenu() {
	printf("Trump.c - Makes Programming Great Again!\n");
	printf("----------------------------------------\n");
	printf("Usage: ./Build [COLOR]\n\n");

	printf("Colors\n");
	printf("------\n");
	printf("  -rw || --red-wall\t\tBuilds a red wall.\n");
	printf("  -gw || --green-wall\t\tBuilds a green wall.\n");
	printf("  -yw || --yellow-wall\t\tBuilds a yellow wall.\n");
	printf("  -bw || --blue-wall\t\tBuilds a blue wall.\n");
	printf("  -mw || --magenta-wall\t\tBuilds a magenta wall.\n");
	printf("  -cw || --cyan-wall\t\tBuilds a cyan wall.\n");
	printf("  -ww || --white-wall\t\tBuilds a white wall.\n\n");

	printf(" * This program is the result of a joke allied with the lazyness from the programmer.\n");
	printf(" * Please, do not take this seriously!\n\n");

	exit(0);
}

/* Main function, catches possible arguments from the terminal */
int main(int argc, char * argv[]) {
	if (argc >= 2) {
		if (0 == strcmp(argv[1], "-rw") || 0 == strcmp(argv[1], "--red-wall")) {
			buildingWall(1);
		}
		else if (0 == strcmp(argv[1], "-gw") || 0 == strcmp(argv[1], "--green-wall")) {
			buildingWall(2);
		}
		else if (0 == strcmp(argv[1], "-yw") || 0 == strcmp(argv[1], "--yellow-wall")) {
			buildingWall(3);
		}
		else if (0 == strcmp(argv[1], "-bw") || 0 == strcmp(argv[1], "--blue-wall")) {
			buildingWall(4);
		}
		else if (0 == strcmp(argv[1], "-mw") || 0 == strcmp(argv[1], "--magenta-wall")) {
			buildingWall(5);
		}
		else if (0 == strcmp(argv[1], "-cw") || 0 == strcmp(argv[1], "--cyan-wall")) {
			buildingWall(6);
		}
		else if (0 == strcmp(argv[1], "-ww") || 0 == strcmp(argv[1], "--white-wall")) {
			buildingWall(7);
		}
		else if (0 == strcmp(argv[1], "-h") || 0 == strcmp(argv[1], "--help")) {
			helpMenu();
		}
		else {
			buildingWall(8);	/* 8 means default color */
		}
	}
	else {
		buildingWall(8);		/* 8 means default color */
	}

	printf(RESET);
	return 0;
}