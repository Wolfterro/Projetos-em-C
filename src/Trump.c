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