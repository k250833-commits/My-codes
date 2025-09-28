#include <stdio.h>
int main() {
	char a;
	float d;
	printf("                     Guidance from the City Traffic Department\n");
	printf("Color of the signal (R is RED, Y is YELLOW, and G is GREEN):\n");
	scanf(" %c",&a);
	printf("Time of the Day:\n");
	scanf(" %2f",&d);
	if(a == 'R' && d < 22.00) {
		printf("Stop and wait\n");
	}
	else if(a == 'R' && d >= 22.00) {
		printf("Stop, but night caution allowed\n");
	}
	else if(a == 'Y') {
		printf("Get Ready\n");
	}
	else if(a == 'G') {
		printf("Go\n");
	}
	else {
		printf("Invalid Signal\n");
	}
	return 0;
			
}
