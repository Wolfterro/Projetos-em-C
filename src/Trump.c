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

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

volatile sig_atomic_t f = 0;

void endHandler(int sig) {
	f = 1;
}

void builtSoFar(long double meters) {
	printf("\nYou've built %.2Lf meters!\n", meters / 10);
	f = 0;
	exit(0);
}

void buildingWall(void) {
	long double meters = 0.0;
	
	signal(SIGINT, endHandler);
	printf("Building wall (press CTRL + C to stop)...\n");
	usleep(1000000);
	
	while(1) {
		if(f) {
			builtSoFar(meters);
		}
		
		printf("|¯¯¯¯");
		fflush(stdout);
		usleep(80000);
		meters += 0.2;
	}
}

int main(int argc, char * argv[]) {
	buildingWall();
	return 0;
}