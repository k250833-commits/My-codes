#include <stdio.h>

int main() {
	int attendance;
	char a,b;
	printf("What is your attendance percentage?\n");
	scanf(" %d", &attendance);
	
if (attendance < 75) {
	printf("You are not eligible\n");
return 0;
}
    printf("Have you passed your midterm exam? (Pass/Fail)\n");
    scanf(" %c", &a);
if (a == 'F') {
	printf("You are not eligible\n");
return 0;
}
    printf("Have you paid the exam fee? (Yes/No)\n");
    scanf(" %c", &b);
if (b == 'N') {
	printf("Please clear your dues to appear in the Final Exam");   
return 0;
}
else  {
	printf("You are eligible for the final exam");
}
return 0;
}
